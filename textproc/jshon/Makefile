# $FreeBSD$

PORTNAME=	jshon
DISTVERSION=	20160111.2
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JSON parser for the shell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjansson.so:devel/jansson

COMMIT_HASH=	783d3bf
GH_TAGNAME=	${COMMIT_HASH}

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	keenerd

OPTIONS_DEFINE=	ZSH
OPTIONS_DEFAULT=

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/jshon man/man1/jshon.1.gz

ZSH_PLIST_FILES=	share/zsh/site-functions/jshon_zsh_completion

pre-configure:
	@${REINPLACE_CMD} -e 's|^\(#define JSHONVER \).*|\1"${PORTVERSION}-${COMMIT_HASH}"|' \
	-e 's|\({printf("%\)i\(\\n", JSHONVER); exit(0);}\)|\1s\2|' \
	${WRKSRC}/jshon.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/jshon_zsh_completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
