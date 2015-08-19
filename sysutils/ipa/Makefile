# Created by: Andrey Simonenko
# $FreeBSD$

PORTNAME=	ipa
PORTVERSION=	2.1.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/ipa-system

MAINTAINER=	sysutils/ipa
COMMENT=	Pluggable accounting system

LICENSE=	BSD2CLAUSE

USES=	tar:bzip2
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

PLIST_FILES=	bin/ipa bin/ipactl bin/ipastat include/ipa_mod.h \
		man/man3/ipa_mod.3.gz man/man5/ipa.conf.5.gz \
		man/man5/ipastat.conf.5.gz man/man8/ipa.8.gz \
		man/man8/ipactl.8.gz man/man8/ipastat.8.gz \
		man/ru.KOI8-R/man3/ipa_mod.3.gz \
		man/ru.KOI8-R/man5/ipa.conf.5.gz \
		man/ru.KOI8-R/man5/ipastat.conf.5.gz \
		man/ru.KOI8-R/man8/ipa.8.gz \
		man/ru.KOI8-R/man8/ipactl.8.gz \
		man/ru.KOI8-R/man8/ipastat.8.gz

.include <bsd.port.mk>
