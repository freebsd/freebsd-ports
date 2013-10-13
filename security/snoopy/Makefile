# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	snoopy
PORTVERSION=	1.9.0
CATEGORIES=	security
MASTER_SITES=	GH \
		GHC

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	execve() wrapper and logger

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/detect lib/snoopy.so
PORTDOCS=	ChangeLog README.md TODO

GNU_CONFIGURE=	yes
USES=		gmake

GH_ACCOUNT=	a2o
GH_COMMIT=	34306f7
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}
USE_GITHUB=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} '/^LIBS=/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' ${WRKSRC}/README.md

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/detect ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/snoopy.so ${STAGEDIR}${PREFIX}/lib/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
