# New ports collection makefile for: NetAMS
# Date created:        24 December 2003
# Whom: 	       jura@netams.com
#
# $FreeBSD$
#

PORTNAME=	netams
PORTVERSION=	3.2.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netams.com/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jura@netams.com
COMMENT=	Network Traffic Accounting and Monitoring Software

USE_SUBMAKE=	yes
MAN8=		netams.8 flowprobe.8 netamsctl.8
MANCOMPRESSED=	no

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}" \

.include <bsd.port.pre.mk>

FLAGS += ${PTHREAD_CFLAGS}
LIB += ${PTHREAD_LIBS}

#MAKE_ENV+=	DEFINE="${DEFINE}" FLAGS="${FLAGS}" LIB="${LIB}"

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/netams ${PREFIX}/libexec/netams
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/flowprobe ${PREFIX}/sbin/flowprobe
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/ipfw2netflow ${PREFIX}/sbin/ipfw2netflow
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/netamsctl ${PREFIX}/bin/netamsctl
	@ ${INSTALL_DATA} ${WRKSRC}/addon/netams.cfg ${PREFIX}/etc/netams.cfg.sample
	@ ${INSTALL_SCRIPT} ${WRKSRC}/addon/netams-startup.sh ${PREFIX}/etc/rc.d/netams-startup.sh.sample
	@ ${INSTALL_MAN} ${WRKSRC}/doc/netams.8 ${PREFIX}/man/man8
	@ ${INSTALL_MAN} ${WRKSRC}/doc/flowprobe.8 ${PREFIX}/man/man8
	@ ${INSTALL_MAN} ${WRKSRC}/doc/netamsctl.8 ${PREFIX}/man/man8
	@ ${MKDIR} ${DATADIR}
	@ ${INSTALL_DATA} ${WRKSRC}/addon/ru-networks.txt ${DATADIR}/ru-networks.txt.sample
	@ ${INSTALL_DATA} ${WRKSRC}/addon/.netamsctl.rc ${DATADIR}
	@ ${MKDIR} ${DATADIR}/cgi-bin
	@ ${MKDIR} ${DATADIR}/cgi-bin/admin
	@ ${MKDIR} ${DATADIR}/cgi-bin/images
.for image in logo.gif logo-small.gif admintool-logo.gif showtable-logo.gif
	@ ${INSTALL_DATA} ${WRKSRC}/cgi-bin/images/${image} ${DATADIR}/cgi-bin/images/
.endfor
.for cgi in .htaccess config.cgi netams_api.pl russian.res weblogin.tem netams_example.cgi \
	usertool.cgi admintool.cgi login.cgi netams_graph.cgi weblogin.cgi
	 @ ${INSTALL_DATA} ${WRKSRC}/cgi-bin/${cgi} ${DATADIR}/cgi-bin/
.endfor
.for cgi in .htaccess index.cgi policy.cgi showusercard.cgi user.cgi access.cgi login.cgi \
	quota.cgi showusercard.tmpl view.cgi account.cgi netams.cgi radius.cgi subplan.cgi \
	config.cgi plan.cgi russian.res unit.cgi
	@ ${INSTALL_DATA} ${WRKSRC}/cgi-bin/admin/${cgi} ${DATADIR}/cgi-bin/admin/
.endfor

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message|${SED} 's|%%DATADIR%%|${DATADIR}|g'

.include <bsd.port.post.mk>
