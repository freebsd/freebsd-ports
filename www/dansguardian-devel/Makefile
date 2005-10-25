# New ports collection makefile for:	dansguardian
# Date created:				April 02, 2002
# Whom:					Freddie Cash <fcash@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	dansguardian
PORTVERSION=	2.9.0.1
CATEGORIES=	www
MASTER_SITES=	# empty, see below
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	fcash@sd73.bc.ca
COMMENT=	A fast, feature-rich web content filter for Squid proxy servers

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid \
		${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13

#IGNORE=		"currently at lower revision than www/dansguardian"

USE_GCC=	3.4+

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

CONFLICTS=	dansguardian-2.[678]*
LATEST_LINK=	dansguardian-devel

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-logdir=/var/log \
		--with-piddir=/var/run

MAN8=		dansguardian.8

OPTIONS=	DG_CLAMAV "Enable ClamAV support (libclamav)" off \
		DG_CLAMD  "Enable ClamAV daemon support (clamd)" off \
		DG_ICAP   "Enable ICAP AV content scanner support" off \
		DG_KASP   "Enable Kaspersky AV support" off \
		DG_DMGR   "Enable the fancy download manager" off
#		DG_PHRASELISTS "Install new phraselists. (Overwrites existing.)" off

DG_URL=		http://dansguardian.org/index.php?page=copyright2
CONFDIR=	${PREFIX}/etc/dansguardian

NO_CDROM=	"Commercial download is restricted.  Check ${DG_URL} for more info"
NO_PACKAGE=	"Redistribution is restricted.  Check ${DG_URL} for more info"
RESTRICTED=	${NO_PACKAGE}

.include <bsd.port.pre.mk>

.if defined(WITH_DG_CLAMAV) && defined(WITH_DG_CLAMD)
BROKEN=	"You have select both ClamAV integration options, which is known to cause issues.  Please select only one of the ClamAV options.  Run make config to change the options"
.endif

.if defined(WITH_DG_CLAMAV)
CONFIGURE_ARGS+=	--enable-clamav=yes
LIB_DEPENDS=		clamav.1:${PORTSDIR}/security/clamav:install
.endif

.if defined(WITH_DG_CLAMD)
CONFIGURE_ARGS+=	--enable-clamd=yes
RUN_DEPENDS+=		${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13
.endif

.if defined(WITH_DG_ICAP)
BROKEN=	"I don't have access to ICAP AV, so I can't test this.  If you have access to it, drop me an e-mail.  Thanks"
.endif

.if defined(WITH_DG_KASP)
BROKEN=	"I don't have access to Kaspersky AV, so I can't test this.  If you have access to it, drop me an e-mail.  Thanks"
.endif

.if defined(WITH_DG_DMGR)
CONFIGURE_ARGS+=	--enable-fancydm
.endif

# User needs to manually download the distfile
.if !(exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})) && !defined(PACKAGE_BUILDING)
IGNORE="Commercial source download is restricted.  Please visit and read ${DG_URL} and download ${DISTNAME}${EXTRACT_SUFX} into ${DISTDIR} before running make"
.endif

post-extract:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/dansguardian.sh > ${WRKSRC}/dansguardian.sh

pre-install:
# Configure pkg-plist based on whether phraselists are to be installed or not
.if defined(WITH_DG_PHRASELISTS)
PLIST_SUB=	PHRASELISTS=""
.else
PLIST_SUB=	PHRASELISTS="@comment "
.endif

post-install:
# Check whether to install default phraselists
.if defined(WITH_DG_PHRASELISTS)
	@${ECHO_MSG} "===>   Installing default phraselists into ${CONFDIR}/phraselists"
	@${CP} -R ${WRKSRC}/phraselists ${CONFDIR}
.else
	@${ECHO_MSG} "===>   Skipping installation of phraselists."
.endif

# Install startup script
	@${ECHO_MSG} "===>   Installing startup script into ${PREFIX}/etc/rc.d"
	@${INSTALL_SCRIPT} ${WRKSRC}/dansguardian.sh ${PREFIX}/etc/rc.d/start-dg.sh

# Display post-install message
	@${CAT} pkg-message

.include <bsd.port.post.mk>
