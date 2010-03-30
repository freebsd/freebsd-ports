# New ports collection makefile for:	argus3-clients
# Date created:		24 March 2004
# Whom:			Stefan Esser <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	argus-clients
PORTVERSION=	3.0.2
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://qosient.com/argus/src/ \
		ftp://qosient.com/pub/argus/src/

MAINTAINER=	support@spectrum.ru
COMMENT=	Client programs for the argus IP network transaction auditing tool

CONFLICTS=	argus-clients-2* argus-clients-sasl-2*

OPTIONS+=	SASL "SASL authentication support" on \
		MYSQL "MySQL database support" on

.include <bsd.port.options.mk>

USE_BISON=	build
GNU_CONFIGURE=	true

.if defined(WITH_SASL)
PKGNAMESUFFIX=	-sasl
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.endif

MAN1=	ra.1 rabins.1 racluster.1 racount.1 ragraph.1 rahisto.1 \
	ranonymize.1 rasort.1 rasplit.1 rastream.1 rastrip.1
MAN5=	racluster.5 radium.conf.5 rarc.5
MAN8=	radium.8

.include <bsd.port.pre.mk>

do-install:
.for i in ra rabins racluster racount radump rafilteraddr \
		rahisto ralabel ranonymize rapath rapolicy \
		raservices rasort rasplit rasql rasqlinsert rastream \
		rastrip ratemplate ratimerange ratop ratree rauserdata
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin/$i
.endfor
.for i in radark ragraph rahosts raports
	${INSTALL_SCRIPT} ${WRKSRC}/bin/$i ${PREFIX}/bin/$i
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.for i in README COPYING doc/CHANGES doc/FAQ doc/HOW-TO
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
	${MKDIR} ${EXAMPLESDIR}
.for i in Config Startup System
	${MKDIR} ${EXAMPLESDIR}/$i
	${INSTALL_DATA} ${WRKSRC}/support/$i/* ${EXAMPLESDIR}/$i
.endfor

.include <bsd.port.post.mk>
