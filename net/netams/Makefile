# New ports collection makefile for: NetAMS
# Date created:        9 December 2002
# Whom: 	       jura@happychance.com
#
# $FreeBSD$
#

PORTNAME=	netams
PORTVERSION=	3.1
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://www.netams.com/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}.1563

MAINTAINER=	jura@happychance.com
COMMENT=	Network Traffic Accounting and Monitoring Software

USE_SUBMAKE=	yes

MAN8=		netams.8
MANCOMPRESSED=	no

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}" \
		WITH_MYSQL="${WITH_MYSQL}" \
		WITH_MYSQL40="${WITH_MYSQL40}" \
		WITH_MYSQL41="${WITH_MYSQL41}" \
		WITH_PGSQL="${WITH_PGSQL}" \
		WITH_DEBUG="${WITH_DEBUG}" \
		LOG_DROP="${LOG_DROP}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.netams

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

MAKE_ENV+=	DEFINE="${DEFINE}" FLAGS="${FLAGS}" LIB="${LIB}"

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/netams ${PREFIX}/libexec/netams
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/netamsctl ${PREFIX}/bin/netamsctl
	@ ${INSTALL_DATA} ${WRKSRC}/addon/netams.cfg ${PREFIX}/etc/netams.conf.sample
	@ ${INSTALL_SCRIPT} ${FILESDIR}/netams.sh ${PREFIX}/etc/rc.d/netams.sh.sample
	@ ${INSTALL_MAN} ${WRKSRC}/doc/netams.8 ${PREFIX}/man/man8
	@ ${MKDIR} ${EXAMPLESDIR}/cgi-bin
	@ ${INSTALL_DATA} ${WRKSRC}/addon/.netamsctl.rc ${EXAMPLESDIR}/
.for example in netams-nat-network.cfg netams-netflow.cfg netams.cfg netams-simple.cfg
	@ ${INSTALL_DATA} ${WRKSRC}/doc/${example} ${EXAMPLESDIR}/
.endfor
.for cgi in logo.gif netams_api.pl netams_graph.cgi weblogin.tem netams_example.cgi weblogin.cgi
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
