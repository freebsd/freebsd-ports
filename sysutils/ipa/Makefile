# New ports collection makefile for:	ipa
# Date created:				2 December 2000
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa
PORTVERSION=	2.0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://ipa-system.sourceforge.net/

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
COMMENT=	Pluggable accounting system

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	ipa

OPTIONS=	AUTORULES "Enable dynamic rules support" on \
		RULES "Enable static rules support" on \
		LIMITS "Enable limits support" on \
		SUBLIMITS "Enable sublimits support" on \
		THRESHOLDS "Enable thresholds support" on \
		CTL_CREDS "Enable ipactl's messages credentials" off \
		MEMFUNC_DEBUG "Enable ipa_memfunc debugging" off \
		DEBUG_INFO "Produce debugging information" off \
		MAN_KOI8_R "Install Russian manual pages" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_AUTORULES)
CONFIGURE_ARGS+=	--disable-autorules
.endif

.if defined(WITHOUT_RULES)
CONFIGURE_ARGS+=	--disable-rules
.endif

.if defined(WITHOUT_LIMITS)
CONFIGURE_ARGS+=	--disable-limits
.endif

.if defined(WITHOUT_SUBLIMITS)
CONFIGURE_ARGS+=	--disable-sublimits
.endif

.if defined(WITHOUT_THRESHOLDS)
CONFIGURE_ARGS+=	--disable-thresholds
.endif

.if defined(WITH_CTL_CREDS)
CONFIGURE_ARGS+=	--enable-ctl-creds
.endif

.if defined(WITH_MEMFUNC_DEBUG)
CONFIGURE_ARGS+=	--enable-memfunc-debug
.endif

.if defined(WITH_DEBUG_INFO)
STRIP=		# empty
CFLAGS+=	-g
.endif

MAN3=		ipa_mod.3
MAN5=		ipa.conf.5 ipastat.conf.5
MAN8=		ipa.8 ipactl.8 ipastat.8
MANLANG=	""
.if defined(WITH_MAN_KOI8_R)
MANLANG+=	ru.KOI8-R
.endif

do-install:
	cd ${WRKSRC}/src && ${MAKE} install
	cd ${WRKSRC}/man && ${MAKE} install-am
.if defined(WITH_MAN_KOI8_R)
	cd ${WRKSRC}/man/ru.KOI8-R && ${MAKE} install
.endif

.include <bsd.port.post.mk>
