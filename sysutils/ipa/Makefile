# New ports collection makefile for:	ipa
# Date created:				2 December 2000
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa
PORTVERSION=	2.1.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/ipa-system

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
COMMENT=	Pluggable accounting system

LICENSE=	BSD

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	ipa

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=		AUTORULES RULES LIMITS SUBLIMITS THRESHOLDS CTL_CREDS
OPTIONS_DEFAULT=	AUTORULES RULES LIMITS SUBLIMITS THRESHOLDS
AUTORULES_DESC=		Enable dynamic rules support
RULES_DESC=		Enable static rules support
LIMITS_DESC=		Enable limits support
SUBLIMITS_DESC=		Enable sublimits support
THRESHOLDS_DESC=	Enable thresholds support
CTL_CREDS_DESC=		Enable ipactl's messages credentials

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MAUTORULES)
CONFIGURE_ARGS+=	--disable-autorules
.endif

.if empty(PORT_OPTIONS:MRULES)
CONFIGURE_ARGS+=	--disable-rules
.endif

.if empty(PORT_OPTIONS:MLIMITS)
CONFIGURE_ARGS+=	--disable-limits
.endif

.if empty(PORT_OPTIONS:MSUBLIMITS)
CONFIGURE_ARGS+=	--disable-sublimits
.endif

.if empty(PORT_OPTIONS:MTHRESHOLDS)
CONFIGURE_ARGS+=	--disable-thresholds
.endif

.if ${PORT_OPTIONS:MCTL_CREDS}
CONFIGURE_ARGS+=	--enable-ctl-creds
.endif

.include <bsd.port.pre.mk>

PLIST_FILES=	bin/ipa bin/ipactl bin/ipastat include/ipa_mod.h

MAN3=		ipa_mod.3
MAN5=		ipa.conf.5 ipastat.conf.5
MAN8=		ipa.8 ipactl.8 ipastat.8
MANLANG=	"" ru.KOI8-R

.include <bsd.port.post.mk>
