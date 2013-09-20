# Created by: brock@cotcomsol.com
# $FreeBSD$

PORTNAME=	argus-monitor
PORTVERSION=	20100109
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.tcp4me.com/code/argus-archive/
DISTNAME=	argus-dev-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Argus - The All Seeing System and Network Monitoring Software

SUB_FILES=	pkg-message apache.conf pkg-install
SUB_LIST=	PORTNAME=${PORTNAME} APACHEETCDIR=${APACHEETCDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
EXTRA_PATCHES=	${FILESDIR}/patch.001

LICENSE=	ART10

WRKSRC=		${WRKDIR}/${DISTNAME}
USES=		perl5
USE_RC_SUBR=	argusd
HAS_CONFIGURE=	yes
USE_APACHE_RUN=	22+
CONFIGURE_SCRIPT=	Configure

OPTIONS_DEFINE=	QPAGE FPING GD
OPTIONS_DEFAULT=GD

QPAGE_DESC=	qpage support
FPING_DESC=	fping support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQPAGE}
BUILD_DEPENDS+=	qpage:${PORTSDIR}/comms/qpage
RUN_DEPENDS+=	qpage:${PORTSDIR}/comms/qpage
.endif

.if ${PORT_OPTIONS:MFPING}
BUILD_DEPENDS+=	fping:${PORTSDIR}/net/fping
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
.endif

.if ${PORT_OPTIONS:MGD}
BUILD_DEPENDS+=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS+=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD
.endif

CONFIGURE_ARGS=	--bin_dir=${PREFIX}/bin \
		--sbin_dir=${PREFIX}/sbin \
		--lib_dir=${PREFIX}/lib/argus-monitor \
		--data_dir=${ETCDIR} \
		--cgi_dir=${WWWDIR}/cgi-bin

post-install:
	@${INSTALL} -m 755 -d ${WWWDIR} ${WWWDIR}/docroot ${WWWDIR}/docroot/img ${WWWDIR}/docroot/sound ${ETCDIR}/notify
	@${CP} ${WRKSRC}/misc/argus.css ${WRKSRC}/misc/argus.js  ${WWWDIR}/docroot/
	@${CP} ${WRKSRC}/misc/argus.logo.gif ${WRKSRC}/misc/nospkr.gif ${WRKSRC}/misc/sad.gif \
		${WRKSRC}/misc/sadred.gif ${WRKSRC}/misc/smile.gif ${WWWDIR}/docroot/img/
	@${CP} ${WRKSRC}/misc/whoopwhoop.wav ${WWWDIR}/docroot/sound/
	@${TOUCH} ${ETCDIR}/notno ${ETCDIR}/log
	@${MKDIR} ${PREFIX}/${APACHEETCDIR}/Includes
	@${INSTALL_DATA} ${WRKDIR}/apache.conf ${PREFIX}/${APACHEETCDIR}/Includes/${PORTNAME}.conf.sample
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
