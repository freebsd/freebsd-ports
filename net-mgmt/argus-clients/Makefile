# New ports collection makefile for:	argus-clients
# Date created:		24 March 2004
# Whom:			Stefan Esser <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	argus-clients
PORTVERSION=	2.0.6
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://qosient.com/argus/src/ \
		ftp://qosient.com/pub/argus/src/

MAINTAINER=	se@freebsd.org
COMMENT=	Client programs for the argus IP network transaction auditing tool

.if defined(WITH_SASL)
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
.endif

USE_BISON=	true
GNU_CONFIGURE=	true
CONFIGURE_ARGS=	--exec-prefix=${PREFIX}
.if defined(WITH_SASL)
CONFIGURE_ARGS+= --with-sasl=${PREFIX}
CFLAGS+=	-I${PREFIX}/include/sasl
.endif

DOCSDIR?=	${PREFIX}/share/doc/argus-2.0
EXAMPLESDIR?=	${PREFIX}/share/examples/argus-2.0

MAN1=	ra.1 racount.1 ragator.1 rahosts.1 ramon.1 ranonymize.1 rapolicy.1 \
	rasort.1 rastrip.1 raxml.1
MAN5=	rarc.5

do-install:
.for i in ra racount ragator ragrep rahistogram rahosts \
		ramon ranonymize rapath rapolicy rarpwatch raseq \
		rasort rasrvstats rastrip ratop raxml
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin/$i
.endfor
.for i in argusbug ragraph
	${INSTALL_SCRIPT} ${WRKSRC}/bin/$i ${PREFIX}/bin/$i
.endfor
.for i in argus_client.a argus_common.a argus_parse.a
	${INSTALL_DATA} ${WRKSRC}/lib/$i ${PREFIX}/lib/$i
.endfor
	${MKDIR} ${PREFIX}/argus/archive
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/argus
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/argus
	${MKDIR} ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/cons_def.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/cons_out.h ${PREFIX}/include
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/support/README ${EXAMPLESDIR}
.for i in Archive Config System Tools Xml
	${MKDIR} ${EXAMPLESDIR}/$i
	${INSTALL_DATA} ${WRKSRC}/support/$i/* ${EXAMPLESDIR}/$i
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html/man
.for i in README COPYING CREDITS doc/CHANGES doc/FAQ doc/HOW-TO
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.for i in hosts_access.5.html hosts_options.5.html ra.1.html \
		racount.1.html ragator.1.html ramon.1.html rarc.5.html \
		rasort.1.html raxml.1.html tcpd.8.html tcpdump.1.html
	${INSTALL_DATA} ${WRKSRC}/doc/html/man/$i ${DOCSDIR}/html/man
.endfor
.endif
.if !defined(NOMAN)
.for i in ${MAN1}
	${INSTALL_DATA} ${WRKSRC}/man/man1/$i ${PREFIX}/man/man1
.endfor
.for i in ${MAN5}
	${INSTALL_DATA} ${WRKSRC}/man/man5/$i ${PREFIX}/man/man5
.endfor
.endif

.include <bsd.port.mk>
