# New ports collection makefile for: NetAMS
# Date created:        24 December 2003
# Whom: 	       jura@netams.com
#
# $FreeBSD$
#

PORTNAME=	netams
PORTVERSION=	3.1
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netams.com/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}.1830

MAINTAINER=	jura@netams.com
COMMENT=	Network Traffic Accounting and Monitoring Software

USE_SUBMAKE=	yes
MAN8=		netams.8 flowprobe.8
MANCOMPRESSED=	no

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}" \
		WITH_MYSQL="${WITH_MYSQL}" \
		WITH_MYSQL40="${WITH_MYSQL40}" \
		WITH_MYSQL41="${WITH_MYSQL41}" \
		WITH_POSTGRESQL="${WITH_POSTGRESQL}" \
		WITH_DEBUG="${WITH_DEBUG}"

.include <bsd.port.pre.mk>

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.netams

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

FLAGS += ${PTHREAD_CFLAGS}
LIB += ${PTHREAD_LIBS}

MAKE_ENV+=	DEFINE="${DEFINE}" FLAGS="${FLAGS}" LIB="${LIB}"

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/netams ${PREFIX}/libexec/netams
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/flowprobe ${PREFIX}/sbin/flowprobe
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/ipfw2netflow ${PREFIX}/sbin/ipfw2netflow
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/netamsctl ${PREFIX}/bin/netamsctl
	@ ${INSTALL_DATA} ${WRKSRC}/addon/netams.cfg ${PREFIX}/etc/netams.conf.sample
	@ ${INSTALL_SCRIPT} ${FILESDIR}/netams.sh ${PREFIX}/etc/rc.d/netams.sh.sample
	@ ${INSTALL_MAN} ${WRKSRC}/doc/netams.8 ${PREFIX}/man/man8
	@ ${INSTALL_MAN} ${WRKSRC}/doc/flowprobe.8 ${PREFIX}/man/man8
	@ ${MKDIR} ${EXAMPLESDIR}/cgi-bin
	@ ${MKDIR} ${EXAMPLESDIR}/cgi-bin/images
	@ ${INSTALL_DATA} ${WRKSRC}/addon/.netamsctl.rc ${EXAMPLESDIR}/
.for example in netams-nat-network.cfg netams-netflow.cfg netams.cfg netams-simple.cfg netams-quotactl.cfg
	@ ${INSTALL_DATA} ${WRKSRC}/doc/${example} ${EXAMPLESDIR}/
.endfor
.for image in logo.gif logo-small.gif admintool-logo.gif
	@ ${INSTALL_DATA} ${WRKSRC}/cgi-bin/images/${image} ${EXAMPLESDIR}/cgi-bin/images/
.endfor
.for cgi in netams_api.pl netams_graph.cgi weblogin.tem netams_example.cgi weblogin.cgi admintool.cgi login.cgi
	 @ ${INSTALL_DATA} ${WRKSRC}/cgi-bin/${cgi} ${EXAMPLESDIR}/cgi-bin/
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for doc in documentation-en.html diagram-1.gif net-1-1a.gif net-1-2a.gif net-1-3a.gif logo.gif
	@ ${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DOCSDIR}/
.endfor
.endif

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message|${SED} 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g'
post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.post.mk>
