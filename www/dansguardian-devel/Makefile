# New ports collection makefile for:	dansguardian
# Date created:				April 02, 2002
# Whom:					Freddie Cash <fcash@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	dansguardian
PORTVERSION=	2.9.6.1
CATEGORIES=	www
MASTER_SITES=	# empty, see below
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	fcash@sd73.bc.ca
COMMENT=	A fast, feature-rich web content filter for Squid proxy servers

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid

USE_GCC=	3.4+
USE_ICONV=	yes

USE_RC_SUBR=	dansguardian.sh

CONFLICTS=	dansguardian-2.[678]*
LATEST_LINK=	dansguardian-devel

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-logdir=/var/log \
		--with-piddir=/var/run

MAN8=		dansguardian.8

OPTIONS=	DG_APACHE  "Enable Apache support for access denied page" on \
		DG_DMGR    "Enable the fancy download manager" on \
		DG_CLAMD   "Enable ClamAV daemon support (clamd)" off \
		DG_CLAMAV  "Enable ClamAV support (libclamav) (broken)" off \
		DG_ICAP    "Enable ICAP AV content scanner support (broken)" off \
		DG_KASP    "Enable Kaspersky AV support (broken)" off

DG_URL=		http://dansguardian.org/index.php?page=copyright2
CONFDIR=	${PREFIX}/etc/dansguardian

NO_CDROM=	Commercial download is restricted.  Check ${DG_URL} for more info
NO_PACKAGE=	Redistribution is restricted.  Check ${DG_URL} for more info
RESTRICTED=	${NO_PACKAGE}

.include <bsd.port.pre.mk>

.if defined(WITH_DG_APACHE)
USE_APACHE=	1.3+
.endif

.if defined(WITH_DG_CLAMAV)
#.if defined(WITH_DG_FORCE_CLAMAV)
#CONFIGURE_ARGS+=	--enable-clamav=yes
#LIB_DEPENDS+=		clamav.1:${PORTSDIR}/security/clamav
#PLIST_SUB+=		CLAMAVCONF=""
#.else
#PLIST_SUB+=		CLAMAVCONF="@comment "
#.endif
#.else
BROKEN=	Please use the clamd plugin support.  It's much more flexible, usable, tested, and just generally better
.endif

.if defined(WITH_DG_CLAMD)
CONFIGURE_ARGS+=	--enable-clamd=yes
RUN_DEPENDS+=		${LOCALBASE}/sbin/clamd:${PORTSDIR}/security/clamav
PLIST_SUB+=		CLAMDCONF=""
.else
PLIST_SUB+=		CLAMDCONF="@comment "
.endif

.if defined(WITH_DG_ICAP)
BROKEN=	I don't have access to ICAP AV, so I can't test this.  If you have access to it, drop me an e-mail.  Thanks
.endif

.if defined(WITH_DG_KASP)
BROKEN=	I don't have access to Kaspersky AV, so I can't test this.  If you have access to it, drop me an e-mail.  Thanks
.endif

.if defined(WITH_DG_DMGR)
CONFIGURE_ARGS+=	--enable-fancydm
#PLIST_SUB+=		DMGR=""
#.else
#PLIST_SUB+=		DMGR="@comment "
.endif

# User needs to manually download the distfile
.if !(exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})) && !defined(PACKAGE_BUILDING)
IGNORE="Commercial source download is restricted.  Please visit and read ${DG_URL} and download ${DISTNAME}${EXTRACT_SUFX} into ${DISTDIR} before running make"
.endif

post-install:
# Display post-install message
	@${CAT} pkg-message

.include <bsd.port.post.mk>
