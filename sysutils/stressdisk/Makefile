# $FreeBSD$

PORTNAME=	stressdisk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.12
CATEGORIES=	sysutils

MAINTAINER=	ed.arrakis@gmail.com
COMMENT=	Stress test your disks before trusting your valuable data to them

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	ncw
GH_TUPLE=	ncw:directio:v1.0.4:ncw_directio/vendor/github.com/ncw/directio

PLIST_FILES=	bin/stressdisk

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
