PORTNAME=	plconfig
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.neon1.net/prog/ \
		http://matt.peterson.org/FreeBSD/ports/

MAINTAINER=	matt@peterson.org
COMMENT=	Tool for configuring HomePlug powerline bridges

ALL_TARGET=	plconfig

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plconfig ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
