# New ports collection makefile for:	argus-monitor
# Date created:				18 November 2006
# Whom:					brock@cotcomsol.com
#
# $FreeBSD$
#

PORTNAME=	argus-monitor
PORTVERSION=	20060722
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.tcp4me.com/code/argus-archive/
DISTNAME=	argus-dev-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	brock@cotcomsol.com
COMMENT=	Argus - The All Seeing System and Network Monitoring Software

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_PERL5=	yes
USE_RC_SUBR=	argusd
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	--bin_dir=${PREFIX}/bin --sbin_dir=${PREFIX}/sbin \
		--lib_dir=${PREFIX}/lib/argus-monitor --data_dir=${PREFIX}/etc/argus-monitor

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

.include <bsd.port.post.mk>
