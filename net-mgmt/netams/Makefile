# New ports collection makefile for: NetAMS
# Date created:        24 December 2003
# Whom: 	       jura@netams.com
#
# $FreeBSD$
#

PORTNAME=	netams
PORTVERSION=	3.3.2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.netams.com/files/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jura@netams.com
COMMENT=	Network Traffic Accounting and Monitoring Software

NO_PACKAGE=	"Depends on kernel"

USE_SUBMAKE=	yes
MANCOMPRESSED=	no

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}"

ADMINCGI=	.htaccess index.cgi policy.cgi showusercard.cgi user.cgi  \
		access.cgi login.cgi quota.cgi showusercard.tmpl view.cgi \
		account.cgi netams.cgi radius.cgi subplan.cgi config.cgi  \
		plan.cgi russian.res unit.cgi
CGI=		.htaccess config.cgi netams_api.pl russian.res \
		netams_example.cgi usertool.cgi admintool.cgi login.cgi \
		netams_graph.cgi
IMAGES=		logo.gif logo-small.gif admintool-logo.gif showtable-logo.gif
MAN8=		netams.8 flowprobe.8 netamsctl.8

SYSDIR?=	/sys

OPTIONS=	DEBUG	"Build with debug symbols"			off \
		BW	"Build with bandwidth limitation functionality"	off \
		HASH	"Build with HASH support"			off

.include <bsd.port.pre.mk>

.if !exists(${SYSDIR})
IGNORE=		could not find the kernel sources in ${SYSDIR}. Please define SYSDIR
.endif

post-patch:
	@${REINPLACE_CMD} -E 's/^(CC).*/\1=$$(CXX)/; s|^(INCLUDE=).*|\1 ${LOCALBASE}/include|; s|^(CFLAGS).*=|\1+=|; /^FLAGS/d' \
		${WRKSRC}/addon/Makefile.common
.if defined(WITHOUT_DEBUG)
	@${REINPLACE_CMD} -e 's|configure.sh|configure.sh -nodebug|' \
		${WRKSRC}/Makefile
.endif

.if defined(WITH_BW)
	@${REINPLACE_CMD} -e 's|#DEFINE += -DHAVE_BW|DEFINE += -DHAVE_BW|' \
		${WRKSRC}/addon/Makefile.common
.endif

.if defined(WITH_HASH)
	@${REINPLACE_CMD} -e 's|#DEFINE += -DUSE_HASH|DEFINE += -DUSE_HASH|' \
		${WRKSRC}/addon/Makefile.common
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/netams ${PREFIX}/libexec/netams
	${INSTALL_PROGRAM} ${WRKSRC}/src/flowprobe ${PREFIX}/sbin/flowprobe
	${INSTALL_PROGRAM} ${WRKSRC}/src/ipfw2netflow \
		${PREFIX}/sbin/ipfw2netflow
	${INSTALL_PROGRAM} ${WRKSRC}/src/netamsctl ${PREFIX}/bin/netamsctl
	${INSTALL_DATA} ${WRKSRC}/addon/netams.cfg \
		${PREFIX}/etc/netams.cfg.sample
.if !exists(${PREFIX}/etc/netams.cfg)
	${INSTALL_DATA} ${WRKSRC}/addon/netams.cfg \
		${PREFIX}/etc/netams.cfg
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/addon/netams-startup.sh \
		${PREFIX}/etc/rc.d/netams-startup.sh.sample
	${MKDIR} ${DATADIR}/cgi-bin/admin ${DATADIR}/cgi-bin/images
	${INSTALL_DATA} ${WRKSRC}/addon/ru-networks.txt \
		${DATADIR}/ru-networks.txt.sample
	${INSTALL_DATA} ${WRKSRC}/addon/.netamsctl.rc ${DATADIR}
.for f in ${IMAGES}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/images/${f} ${DATADIR}/cgi-bin/images
.endfor
.for f in ${CGI}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/${f} ${DATADIR}/cgi-bin
.endfor
.for f in ${ADMINCGI}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/admin/${f} ${DATADIR}/cgi-bin/admin
.endfor
.for f in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${PREFIX}/man/man8
.endfor

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g; s|%%DATADIR%%|${DATADIR}|g' \
		${PKGMESSAGE}

.include <bsd.port.post.mk>
