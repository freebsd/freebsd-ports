# New ports collection makefile for:	argus3-clients
# Date created:		24 March 2004
# Whom:			Stefan Esser <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	argus-clients
PORTVERSION=	3.0.0
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://qosient.com/argus/src/ \
		ftp://qosient.com/pub/argus/src/

MAINTAINER=	se@freebsd.org
COMMENT=	Client programs for the argus IP network transaction auditing tool

OPTIONS+=	SASL "SASL authentication support 1" on \
		DEBUG "Enable debug" off

.include <bsd.port.pre.mk>

.if defined(WITH_SASL)
PKGNAMESUFFIX=	-sasl
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
.endif

USE_BISON=	build
GNU_CONFIGURE=	true

.if defined(WITH_SASL)
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif

MAN1=	ra.1 rabins.1 racluster.1 racount.1 ragraph.1 ragrep.1 rahisto.1 \
	rasort.1 rasplit.1 rastrip.1
MAN5=	racluster.5 radium.conf.5 rarc.5
MAN8=	radium.8

pre-configure:
.if defined(WITH_DEBUG)
	${TOUCH} ${WRKSRC}/.debug
.endif

do-install:
.for i in ra rabins racluster racount radump rafilteraddr \
		ragrep rahisto ralabel ranonymize rapath rapolicy \
		rasort rasplit rastream rastrip ratemplate \
		ratimerange ratop ratree
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin/$i
.endfor
.for i in argusbug radark ragraph rahosts raports
	${INSTALL_SCRIPT} ${WRKSRC}/bin/$i ${PREFIX}/bin/$i
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.for i in README COPYING CREDITS doc/CHANGES doc/FAQ doc/HOW-TO
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif
.if !defined(NOMAN)
.for i in ${MAN1}
	${INSTALL_DATA} ${WRKSRC}/man/man1/$i ${MANPREFIX}/man/man1
.endfor
.for i in ${MAN5}
	${INSTALL_DATA} ${WRKSRC}/man/man5/$i ${MANPREFIX}/man/man5
.endfor
.for i in ${MAN8}
	${INSTALL_DATA} ${WRKSRC}/man/man8/$i ${MANPREFIX}/man/man8
.endfor
.endif
.for i in argus_client.a argus_common.a argus_parse.a
	${INSTALL_DATA} ${WRKSRC}/lib/$i ${PREFIX}/lib/$i
.endfor
	${INSTALL_DATA} ${WRKSRC}/include/cons_def.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/cons_out.h ${PREFIX}/include
	${MKDIR} ${EXAMPLESDIR}
.for i in Config Startup System
	${MKDIR} ${EXAMPLESDIR}/$i
	${INSTALL_DATA} ${WRKSRC}/support/$i/* ${EXAMPLESDIR}/$i
.endfor

.include <bsd.port.post.mk>
