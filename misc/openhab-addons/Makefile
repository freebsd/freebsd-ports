PORTNAME=	openhab-addons
PORTVERSION=	4.3.7
CATEGORIES=	misc java
MASTER_SITES=	https://openhab.jfrog.io/artifactory/libs-release-local/org/openhab/distro/openhab-addons/${PORTVERSION}/
DISTNAME=	openhab-addons-${PORTVERSION}
EXTRACT_SUFX=	.kar

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Addons for openhab
WWW=		https://www.openhab.org/

LICENSE=	EPL

RUN_DEPENDS=	${LOCALBASE}/libexec/openhab/addons/README:misc/openhab

USES=		cpe zip

USERS=	openhab
GROUPS=	openhab

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS="-v"
EXTRACT_AFTER_ARGS="${EXTRACT_WRKDIR}"

CPE_PRODUCT=	openhab

PLIST_FILES=	libexec/openhab/addons/openhab-addons-${PORTVERSION}.kar

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/openhab
	 ${MKDIR} ${STAGEDIR}${PREFIX}/libexec/openhab/addons
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${PREFIX}/libexec/openhab/addons/)

.include <bsd.port.mk>
