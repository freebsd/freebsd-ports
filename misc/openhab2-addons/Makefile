# Created by: Alexander Leidinger
# $FreeBSD$

PORTNAME=	openhab2-addons
PORTVERSION=	2.3.0
CATEGORIES=	misc java
MASTER_SITES=	https://bintray.com/openhab/mvn/download_file?file_path=org%2Fopenhab%2Fdistro%2Fopenhab-addons%2F${PORTVERSION}/
DISTNAME=	openhab-addons-${PORTVERSION}
EXTRACT_SUFX=	.kar

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Addons for openhab2

LICENSE=	EPL

RUN_DEPENDS=	${LOCALBASE}/libexec/openhab2/addons/README:misc/openhab2

USERS=	openhab
GROUPS=	openhab

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS="-v"
EXTRACT_AFTER_ARGS="${EXTRACT_WRKDIR}"

PLIST_FILES=	libexec/openhab2/addons/openhab-addons-2.3.0.kar

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/openhab2
	 ${MKDIR} ${STAGEDIR}${PREFIX}/libexec/openhab2/addons
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${PREFIX}/libexec/openhab2/addons/)

.include <bsd.port.mk>
