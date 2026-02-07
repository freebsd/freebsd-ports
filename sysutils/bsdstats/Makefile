PORTNAME=	bsdstats
PORTVERSION=	7.0
PORTREVISION=	3
CATEGORIES=	sysutils
DISTFILES=

MAINTAINER=	scrappy@hub.org
COMMENT=	Monthly script for reporting anonymous statistics about your machine
WWW=		https://www.bsdstats.org/

LICENSE=	BSD4CLAUSE

BROKEN=		mastersite gives PHP fatal error as of 20250701

NO_BUILD=	yes
USE_RC_SUBR=	bsdstats
SUB_FILES=	300.statistics bsdstats-send pkg-message
SUB_LIST+=	VERSION=${PORTVERSION}
NO_ARCH=	YES

PLIST_FILES=	bin/bsdstats-send \
		etc/periodic/monthly/300.statistics

OPTIONS_DEFINE=	TOR
TOR_DESC=	Submit securely through TOR anonymity network

TOR_RUN_DEPENDS=	tor:security/tor

pre-install-TOR-on:
	@${REINPLACE_CMD} -e 's|USE_TOR=NO|USE_TOR=YES|' ${WRKDIR}/300.statistics
	@${REINPLACE_CMD} -e 's|# REQUIRE: LOGIN|# REQUIRE: LOGIN tor|' ${WRKDIR}/bsdstats
	@${REINPLACE_CMD} -e 's|@@TOR_MESSAGE@@|Statistics will be submitted anonymously through the TOR network|' \
	    ${WRKDIR}/pkg-message

pre-install-TOR-off:
	@${REINPLACE_CMD} -e 's|@@TOR_MESSAGE@@|You can build bsdstats with TOR port option to submit anonymously|' \
	    ${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/monthly
	${INSTALL_SCRIPT} ${WRKDIR}/300.statistics \
		${STAGEDIR}${PREFIX}/etc/periodic/monthly
	${INSTALL_SCRIPT} ${WRKDIR}/bsdstats-send \
		${STAGEDIR}${PREFIX}/bin/bsdstats-send

.include <bsd.port.mk>
