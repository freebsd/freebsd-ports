# New ports collection makefile for:	rwhois
# Version required:			1.0b9.2
# Date created:				May 9th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	rwhois-1.0B9.2
PKGNAME=	rwhois-1.0b9.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.rwhois.net/pub/

MAINTAINER=	jfitz@FreeBSD.org

.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}/lib/rwhois
INSTALL_TARGET=	install install-sample-data install-chroot

MAN8=		rmkdbindex.8 rwhoisd.8

.include <bsd.port.pre.mk>

PLIST=		${WRKDIR}/PLIST
.if ${OSVERSION} < 400011
pre-install:
	@${SED} -e "/libc.so.4/d" \
		${PKGDIR}/PLIST > ${PLIST}
.else
pre-install:
	@${SED} -e "/libc.so.3/d" \
		${PKGDIR}/PLIST > ${PLIST}
.endif

post-install:
	${MKDIR} -p ${PREFIX}/share/doc/rwhois
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/rwhois
	${MV} ${PREFIX}/share/doc/rwhois/rmkdbindex.8 ${PREFIX}/man/man8	
	${MV} ${PREFIX}/share/doc/rwhois/rwhoisd.8 ${PREFIX}/man/man8	
	@ ${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/rwhoisd.sh startup file..."
	@ ${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/rwhoisd.sh
	@ ${ECHO} "#" >> ${PREFIX}/etc/rc.d/rwhoisd.sh
	@ ${ECHO} "" >> ${PREFIX}/etc/rc.d/rwhoisd.sh
	@ ${ECHO} "# remove or comment the following line and uncomment the one below it once you have" >> ${PREFIX}/etc/rc.d/rwhoisd.sh
	@ ${ECHO} "# configured your server's data" >> ${PREFIX}/etc/rc.d/rwhoisd.sh
	@ ${ECHO} "${ECHO} \"rwhoisd not started; sample data still in place.   See ${PREFIX}/share/doc/rwhois for details.\"" >> ${PREFIX}/etc/rc.d/rwhoisd.sh 
	@ ${ECHO} "#[ -x ${PREFIX}/lib/rwhois/sbin/rwhoisd ] && ${PREFIX}/lib/rwhois/sbin/rwhoisd -c ${PREFIX}/lib/rwhois/rwhois.conf & && ${ECHO} -n ' rwhoisd'" >> ${PREFIX}/etc/rc.d/rwhoisd.sh
	${CHMOD} 751 ${PREFIX}/etc/rc.d/rwhoisd.sh

.include <bsd.port.post.mk>
