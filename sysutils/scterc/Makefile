# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scterc
PORTVERSION=	0.0.1
CATEGORIES=	sysutils

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Configure SCT ERC for hard disks on system startup

RUN_DEPENDS=	smartctl:sysutils/smartmontools

USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3
GH_PROJECT=	${PORTNAME}-rc.d

NO_BUILD=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	etc/rc.d/scterc
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/scterc.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scterc.sh ${STAGEDIR}${PREFIX}/etc/rc.d/scterc
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
