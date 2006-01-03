# New ports collection makefile for:	ipa
# Date created:				2 December 2000
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://ipa-system.sourceforge.net/ \
		http://www.mirrors.wiretapped.net/security/network-monitoring/ipa/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/network-monitoring/ipa/ \
		http://ipa.it-ss.be/

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
COMMENT=	Pluggable accounting system

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	yes

OPTIONS=	AUTORULES "Enable dynamic rules support" on \
		RULES "Enable static rules support" on \
		LIMITS "Enable limits support" on \
		SUBLIMITS "Enable sublimits support" on \
		THRESHOLDS "Enable thresholds support" on \
		CTL_CREDS "Enable ipactl's messages credentials" on \
		MEMFUNC_DEBUG "Enable ipa_memfunc debugging" off \
		DEBUG_INFO "Produce debugging information" off \
		MAN_KOI8_R "Install Russian manual pages" off

.include <bsd.port.pre.mk>

.ifdef WITHOUT_AUTORULES
CONFIGURE_ARGS+=	--disable-autorules
.endif

.ifdef WITHOUT_RULES
CONFIGURE_ARGS+=	--disable-rules
.endif

.ifdef WITHOUT_LIMITS
CONFIGURE_ARGS+=	--disable-limits
.endif

.ifdef WITHOUT_SUBLIMITS
CONFIGURE_ARGS+=	--disable-sublimits
.endif

.ifdef WITHOUT_THRESHOLDS
CONFIGURE_ARGS+=	--disable-thresholds
.endif

.ifdef WITHOUT_CTL_CREDS
CONFIGURE_ARGS+=	--disable-ctl-creds
.endif

.ifdef WITH_MEMFUNC_DEBUG
CONFIGURE_ARGS+=	--enable-memfunc-debug
.endif

.ifdef WITH_DEBUG_INFO
STRIP=		# empty
CFLAGS+=	-g
.endif

MAN3=		ipa_mod.3
MAN5=		ipa.conf.5 ipastat.conf.5
MAN8=		ipa.8 ipactl.8 ipastat.8
MANLANG=	""
.ifdef WITH_MAN_KOI8_R
MANLANG+=	ru.KOI8-R
.endif

RC_SCRIPT_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

post-build:
	@${SED} ${RC_SCRIPT_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/ipa.sh > ${WRKSRC}/ipa.sh

do-install:
	cd ${WRKSRC}/src && make install
	cd ${WRKSRC}/man && make install-am
	${INSTALL_SCRIPT} ${WRKSRC}/ipa.sh ${PREFIX}/etc/rc.d
.ifdef WITH_MAN_KOI8_R
	cd ${WRKSRC}/man/ru.KOI8-R && make install
.endif

.include <bsd.port.post.mk>
