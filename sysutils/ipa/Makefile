PORTNAME=	ipa
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/ipa-system

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pluggable accounting system

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:bzip2
GNU_CONFIGURE=	yes
USE_RC_SUBR=	ipa

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

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=		AUTORULES RULES LIMITS SUBLIMITS THRESHOLDS CTL_CREDS
OPTIONS_DEFAULT=	AUTORULES RULES LIMITS SUBLIMITS THRESHOLDS
AUTORULES_DESC=		Enable dynamic rules support
RULES_DESC=		Enable static rules support
LIMITS_DESC=		Enable limits support
SUBLIMITS_DESC=		Enable sublimits support
THRESHOLDS_DESC=	Enable thresholds support
CTL_CREDS_DESC=		Enable ipactl's messages credentials

AUTORULES_CONFIGURE_ENABLE=	autorules
RULES_CONFIGURE_ENABLE=		rules
LIMITS_CONFIGURE_ENABLE=	limits
SUBLIMITS_CONFIGURE_ENABLE=	sublimits
THRESHOLDS_CONFIGURE_ENABLE=	thresholds
CTL_CREDS_CONFIGURE_ENABLE=	ctl-creds

.include <bsd.port.mk>
