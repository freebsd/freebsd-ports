# New ports collection makefile for:	rwhois
# Date created:				May 9th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rwhois
PORTVERSION=	1.0.b9.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.rwhois.net/pub/
DISTNAME=	rwhois-1.0B9.2

MAINTAINER=	jfitz@FreeBSD.org

.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}/lib/rwhois
INSTALL_TARGET=	install install-sample-data install-chroot

MAN8=		rmkdbindex.8 rwhoisd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400011
LIBCVERSION=	3.1
.else
LIBCVERSION=	4
.endif
PLIST_SUB=	LIBCVERSION=${LIBCVERSION}

post-install:
	${MKDIR} -p ${PREFIX}/share/doc/rwhois
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/rwhois
	${MV} ${PREFIX}/share/doc/rwhois/rmkdbindex.8 ${PREFIX}/man/man8	
	${MV} ${PREFIX}/share/doc/rwhois/rwhoisd.8 ${PREFIX}/man/man8	
	@ ${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/rwhoisd.sh startup file..."
	${INSTALL_SCRIPT} -m 751 ${FILESDIR}/rwhoisd.sh ${PREFIX}/etc/rc.d/rwhoisd.sh

.include <bsd.port.post.mk>
