# New ports collection makefile for:	dansguardian
# Date created:				March 26, 2002
# Whom:					Freddie Cash <fcash@sd73.bc.ca>
#
# $FreeBSD$
#

PORTNAME=	dansguardian
PORTVERSION=	2.8.0.2
CATEGORIES=	www
MASTER_SITES=	# empty, see below
DISTNAME=	${PORTNAME}-${PORTVERSION}.source

MAINTAINER=	fcash@sd73.bc.ca
COMMENT=	A fast, feature-rich web content filter for Squid proxy servers

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid \
		${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

CONFLICTS=	dansguardian-2.[67]*
LATEST_LINK=	dansguardian

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=/sbin/ \
		--sysconfdir=/etc/dansguardian/ \
		--sysvdir=/etc/rc.d/ \
		--mandir=/man/ \
		--logdir=/var/log/ \
		--cgidir=/www/cgi-bin/ \
		--piddir=/var/run/
MAN8=		dansguardian.8

OPTIONS=	DG_GCC3 "Compile using GCC 3.3 on FreeBSD 4.x." off \
		DG_PHRASELISTS "Install new phraselists. (Overwrites existing.)" off

DG_URL=		http://dansguardian.org/index.php?page=copyright2
CONFDIR=	${PREFIX}/etc/dansguardian

NO_CDROM=	"Commercial download is restricted.  Check ${DG_URL} for more info"
NO_PACKAGE=	"Redistribution is restricted.  Check ${DG_URL} for more info"
RESTRICTED=	${NO_PACKAGE}

.include <bsd.port.pre.mk>

# Set which version of GCC to compile the port with
.if ${OSVERSION} > 500000
CONFIGURE_ARGS+=	--gccver=3
.else
CONFIGURE_ARGS+=	--gccver=2
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
