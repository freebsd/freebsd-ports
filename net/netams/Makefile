# New ports collection makefile for: NetAMS
# Date created:        9 December 2002
# Whom: 	       jura@happychance.com
#
# $FreeBSD$
#

PORTNAME=	netams
PORTVERSION=	3.1
CATEGORIES=	net
MASTER_SITES=	http://www.netams.com/
DISTNAME=	netams-3.1.1376

MAINTAINER=	jura@happychance.com
COMMENT=	Network Traffic Accounting and Monitoring Software

.if !defined(WITHOUT_MYSQL)
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.endif

MAN8=           netams.8
MANCOMPRESSED=  no

WRKSRC=		${WRKDIR}/netams

DEFINE=		-DFREEBSD
LIB=		-pthread -lpcap -lutil

.if !defined(WITHOUT_MYSQL)
DEFINE+=	-DUSE_MYSQL
LIB+=		-l mysqlclient -L${LOCALBASE}/lib/mysql
.endif
.if defined(LOG_DROP)
DEFINE+=	-DLOG_DROP
.endif
.if defined(MAX_QUOTA)
DEFINE+=	-DMAX_QUOTA=${MAX_QUOTA}
.else
DEFINE+=	-DMAX_QUOTA=32
.endif

SCRIPTS_ENV='DEFINE=${DEFINE}' 'LIB=${LIB}'

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500000
.endif

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
.for cgi in logo.gif netams_api.pl netams_graph.cgi weblogin.tem lucon.ttf netams_example.cgi weblogin.cgi
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

.include <bsd.port.post.mk>
