# New ports collection makefile for:	argus
# Date created:		26 November 1998
# Whom:			Jonathan Hanna <jhanna@home.com>
#
# $FreeBSD$
#

PORTNAME=	argus
PORTVERSION=	2.0.5
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://qosient.com/argus/src/ \
		ftp://qosient.com/pub/argus/src/

MAINTAINER=	se@freebsd.org
COMMENT=	A generic IP network transaction auditing tool

.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif
.if defined(WITH_SASL)
LIB_DEPENDS+=	sasl.8:${PORTSDIR}/security/cyrus-sasl
.endif

USE_BISON=	true
GNU_CONFIGURE=	true
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} #--without-flex --without-bison
.if defined(WITH_SASL)
CONFIGURE_ARGS+=	--with-sasl=${PREFIX}
CFLAGS+=	-I${PREFIX}/include/sasl
.endif

MAN1=	ra.1 racount.1 ragator.1 ramon.1 rasort.1 raxml.1
MAN5=	argus.5 argus.conf.5 rarc.5
MAN8=	argus.8

pre-install:
	${MKDIR} ${PREFIX}/argus/archive
	${INSTALL_DATA} ${WRKSRC}/include/cons_def.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/cons_out.h ${PREFIX}/include
	${MKDIR} ${PREFIX}/share/examples/argus-2.0
	${INSTALL_DATA} ${WRKSRC}/support/README ${PREFIX}/share/examples/argus-2.0
.for i in Archive Config Deployment Startup System Xml
	${MKDIR} ${PREFIX}/share/examples/argus-2.0/$i
	${INSTALL_DATA} ${WRKSRC}/support/$i/* ${PREFIX}/share/examples/argus-2.0/$i
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/argus-2.0/html/man
.for i in README COPYING CREDITS doc/CHANGES doc/FAQ doc/HOW-TO
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/argus-2.0
.endfor
.for i in  doc/html/man/*.html
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/argus-2.0/html/man
.endfor
.endif

.include <bsd.port.mk>
