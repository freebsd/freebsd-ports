# $FreeBSD$

PORTNAME=	jshon
DISTVERSION=	20170302.1
CATEGORIES=	textproc

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	JSON parser for the shell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjansson.so:devel/jansson

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	keenerd
GH_TAGNAME=	d919aea

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/jshon man/man1/jshon.1.gz

OPTIONS_DEFINE=	ZSH
OPTIONS_DEFAULT=ZSH

ZSH_PLIST_FILES=	share/zsh/site-functions/jshon_zsh_completion

pre-configure:
	@${REINPLACE_CMD} -e 's|^\(#define JSHONVER \).*|\1"${PORTVERSION}-${GH_TAGNAME}"|' \
	-e 's|\({printf("%\)i\(\\n", JSHONVER); exit(0);}\)|\1s\2|' \
	${WRKSRC}/jshon.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/jshon_zsh_completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
