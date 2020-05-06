# $FreeBSD$

PORTNAME=	hblock
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.6
CATEGORIES=	net

MAINTAINER=	vulcan@wired.sh
COMMENT=	Adblocker using automatically generated hosts file

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USE_GITHUB=	yes
GH_ACCOUNT=	hectorm

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/hosts/!s|/etc|${PREFIX}/etc|g' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
