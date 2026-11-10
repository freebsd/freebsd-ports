PORTNAME=	vitaly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.32
CATEGORIES=	sysutils

MAINTAINER=	alven@FreeBSD.org
COMMENT=	VIA/Vial CLI configuration tool for QMK keyboards
WWW=		https://github.com/bskaplou/vitaly/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	bskaplou

PLIST_FILES=	bin/vitaly
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
