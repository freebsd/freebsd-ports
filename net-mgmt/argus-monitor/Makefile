# New ports collection makefile for:	argus-monitor
# Date created:				18 November 2006
# Whom:					brock@cotcomsol.com
#
# $FreeBSD$
#

PORTNAME=	argus-monitor
PORTVERSION=	20100109
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.tcp4me.com/code/argus-archive/
DISTNAME=	argus-dev-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	brock@cotcomsol.com
COMMENT=	Argus - The All Seeing System and Network Monitoring Software

SUB_FILES=	pkg-message apache.conf
SUB_LIST=	PORTNAME=${PORTNAME} APACHEETCDIR=${APACHEETCDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
EXTRA_PATCHES=	${FILESDIR}/patch.001

LICENSE=	ART10

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_PERL5=	yes
USE_RC_SUBR=	argusd
HAS_CONFIGURE=	yes
USE_APACHE=	1.3+
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	--bin_dir=${PREFIX}/bin --sbin_dir=${PREFIX}/sbin \
		--lib_dir=${PREFIX}/lib/argus-monitor --data_dir=${PREFIX}/etc/argus-monitor \
		--cgi_dir=${PREFIX}/www/${PORTNAME}/cgi-bin

OPTIONS=	QPAGE	"qpage support" Off \
		FPING	"fping support" Off \
		GD	"GD graphics support" On

.include <bsd.port.pre.mk>

.if defined(WITH_QPAGE)
RUN_DEPENDS+=	qpage:${PORTSDIR}/comms/qpage
BUILD_DEPENDS+=	qpage:${PORTSDIR}/comms/qpage
.endif

.if defined(WITH_FPING)
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
BUILD_DEPENDS+=	fping:${PORTSDIR}/net/fping
.endif

.if !defined(WITHOUT_GD)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD
.endif

post-install:
	${MKDIR} ${PREFIX}/www/${PORTNAME} ${PREFIX}/www/${PORTNAME}/docroot ${PREFIX}/www/${PORTNAME}/docroot/img ${PREFIX}/www/${PORTNAME}/docroot/sound ${PREFIX}/etc/argus-monitor/notify
	${CP} ${WRKSRC}/misc/argus.css ${WRKSRC}/misc/argus.js  ${PREFIX}/www/${PORTNAME}/docroot
	${CP} ${WRKSRC}/misc/argus.logo.gif ${WRKSRC}/misc/nospkr.gif ${WRKSRC}/misc/sad.gif ${WRKSRC}/misc/sadred.gif ${WRKSRC}/misc/smile.gif	${PREFIX}/www/${PORTNAME}/docroot/img
	${CP} ${WRKSRC}/misc/whoopwhoop.wav ${PREFIX}/www/${PORTNAME}/docroot/sound
	${TOUCH} ${PREFIX}/etc/argus-monitor/notno ${PREFIX}/etc/argus-monitor/log
	${CHMOD} 755 ${PREFIX}/www/${PORTNAME} ${PREFIX}/www/${PORTNAME}/docroot ${PREFIX}/www/${PORTNAME}/docroot/img ${PREFIX}/www/${PORTNAME}/docroot/sound ${PREFIX}/etc/argus-monitor/notify
	${CHMOD} 644 ${PREFIX}/www/${PORTNAME}/docroot/argus.* ${PREFIX}/www/${PORTNAME}/docroot/img/*.gif ${PREFIX}/www/${PORTNAME}/docroot/sound/*.wav ${PREFIX}/etc/argus-monitor/notno ${PREFIX}/etc/argus-monitor/log
	${MKDIR} ${PREFIX}/${APACHEETCDIR}/Includes
	${INSTALL_DATA} ${WRKDIR}/apache.conf ${PREFIX}/${APACHEETCDIR}/Includes/${PORTNAME}.conf.sample
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
