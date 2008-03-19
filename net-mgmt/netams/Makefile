# New ports collection makefile for: NetAMS
# Date created:        24 December 2003
# Whom: 	       jura@netams.com
#
# $FreeBSD$
#

PORTNAME=	netams
DISTVERSION=	3.4.0rc2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.netams.com/files/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jura@netams.com
COMMENT=	Network Traffic Accounting and Monitoring Software

NO_PACKAGE=	Depends on installed SQL database

USE_SUBMAKE=	yes
USE_RC_SUBR=	netams
MANCOMPRESSED=	no

SUB_FILES=	pkg-message

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}"

ADMINCGI=	.htaccess index.cgi policy.cgi showusercard.cgi user.cgi  \
		access.cgi login.cgi quota.cgi showusercard.tmpl view.cgi \
		account.cgi netams.cgi radius.cgi subplan.cgi config.cgi  \
		plan.cgi russian.res unit.cgi cardtool.cgi
CGI=		.htaccess config.cgi netams_api.pl russian.res \
		netams_example.cgi usertool.cgi admintool.cgi login.cgi \
		netams_graph.cgi activate.cgi activate.tmpl
IMAGES=		logo.gif logo_sm.jpg admintool-logo.gif showtable-logo.gif
MAN8=		netams.8 flowprobe.8 netamsctl.8

OPTIONS=	DEBUG	"Build with debug symbols"			off \
		BW	"Build with bandwidth limitation functionality"	off \
		HASH	"Build with HASH support"			off

.include <bsd.port.pre.mk>

post-patch:
.if defined(WITHOUT_DEBUG)
	@${REINPLACE_CMD} -e 's|configure.sh|configure.sh -nodebug|' \
		${WRKSRC}/Makefile
.endif

.if defined(WITH_BW)
	@${REINPLACE_CMD} -e 's|#DEFINE += -DHAVE_BW|DEFINE += -DHAVE_BW|' \
		${WRKSRC}/configure.sh
.endif

.if defined(WITH_HASH)
	@${REINPLACE_CMD} -e 's|#DEFINE += -DUSE_HASH|DEFINE += -DUSE_HASH|' \
		${WRKSRC}/configure.sh
.endif
	@${REINPLACE_CMD} -e 's|^CC.*|CC=${CXX}|; s|^CPP.*|CPP=${CXX}|' \
		${WRKSRC}/src/Makefile 
	@${REINPLACE_CMD} -e 's|^CC.*|CC=${CC}|; s|^CPP.*|CPP=${CXX}|' \
		${WRKSRC}/lib/Makefile \
		${WRKSRC}/lib/libipulog/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/netams ${PREFIX}/libexec/netams
	${INSTALL_PROGRAM} ${WRKSRC}/src/flowprobe ${PREFIX}/sbin/flowprobe
	${INSTALL_PROGRAM} ${WRKSRC}/src/ipfw2netflow ${PREFIX}/sbin/ipfw2netflow
	${INSTALL_PROGRAM} ${WRKSRC}/src/ascii2netflow ${PREFIX}/sbin/ascii2netflow
	${INSTALL_PROGRAM} ${WRKSRC}/src/netamsctl ${PREFIX}/bin/netamsctl
	${INSTALL_DATA} ${WRKSRC}/addon/netams.cfg ${PREFIX}/etc/netams.cfg.sample
	${MKDIR} ${DATADIR}/cgi-bin/admin ${DATADIR}/cgi-bin/images
	${INSTALL_DATA} ${WRKSRC}/addon/ru-networks.txt ${DATADIR}/ru-networks.txt.sample
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
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${MAN8PREFIX}/man/man8
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
