# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	snoopy
PORTVERSION=	1.9.0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	execve() wrapper and logger

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USES=		gmake

PLIST_FILES=	bin/detect lib/snoopy.so
PORTDOCS=	ChangeLog README.md TODO

GH_ACCOUNT=	a2o
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} '/^LIBS=/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' ${WRKSRC}/README.md

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/detect ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/snoopy.so ${STAGEDIR}${PREFIX}/lib/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
