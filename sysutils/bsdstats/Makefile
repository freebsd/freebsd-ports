# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdstats
PORTVERSION=	6.0
CATEGORIES=	sysutils
DISTFILES=

MAINTAINER=	yuri@rawbw.com
COMMENT=	Monthly script for reporting anonymous statistics about your machine

LICENSE=	BSD4CLAUSE

NO_BUILD=	yes
USE_RC_SUBR=	bsdstats
SUB_FILES=	300.statistics bsdstats-send pkg-message
SUB_LIST+=	VERSION=${PORTVERSION}
NO_ARCH=	YES

OPTIONS_DEFINE=	TOR
TOR_DESC=	Submit securely through TOR anonymity network

PLIST_FILES=	bin/bsdstats-send \
		etc/periodic/monthly/300.statistics

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTOR}
RUN_DEPENDS+=	tor:security/tor
.endif

pre-install:
.if ${PORT_OPTIONS:MTOR}
	@${REINPLACE_CMD} -e 's|USE_TOR=NO|USE_TOR=YES|' ${WRKDIR}/300.statistics
	@${REINPLACE_CMD} -e 's|# REQUIRE: LOGIN|# REQUIRE: LOGIN tor|' ${WRKDIR}/bsdstats
	@${REINPLACE_CMD} -e 's|@@TOR_MESSAGE@@|Statistics will be submitted anonymously through the TOR network|' \
	    ${WRKDIR}/pkg-message
.else
	@${REINPLACE_CMD} -e 's|@@TOR_MESSAGE@@|You can build bsdstats with TOR port option to submit anonymously|' \
	    ${WRKDIR}/pkg-message
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/monthly
	${INSTALL_SCRIPT} ${WRKDIR}/300.statistics \
		${STAGEDIR}${PREFIX}/etc/periodic/monthly
	${INSTALL_SCRIPT} ${WRKDIR}/bsdstats-send \
		${STAGEDIR}${PREFIX}/bin/bsdstats-send

.include <bsd.port.post.mk>
