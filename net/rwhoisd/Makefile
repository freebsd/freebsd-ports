# New ports collection makefile for:	rwhois
# Version required:			1.0b9.2
# Date created:				May 9th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.4 1998/10/14 00:19:56 jseger Exp $
#

DISTNAME=	rwhois-1.0B9.2
PKGNAME=	rwhois-1.0b9.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.rwhois.net/pub/

MAINTAINER=	jfitz@FreeBSD.ORG

LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper

HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}/lib/rwhois
INSTALL_TARGET=	install install-sample-data install-chroot

MAN8=		rmkdbindex.8 rwhoisd.8

post-install:
	${MKDIR} -p ${PREFIX}/share/doc/rwhois
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/rwhois
	${MV} ${PREFIX}/share/doc/rwhois/rmkdbindex.8 ${PREFIX}/man/man8	
	${MV} ${PREFIX}/share/doc/rwhois/rwhoisd.8 ${PREFIX}/man/man8	
	@ echo "Installing ${PREFIX}/etc/rc.d/rwhoisd.sh startup file..."
	@ echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/rwhoisd.sh
	@ echo "#" >> ${PREFIX}/etc/rc.d/rwhoisd.sh
	@ echo "" >> ${PREFIX}/etc/rc.d/rwhoisd.sh
	@ echo "# remove or comment the following line and uncomment the one below it once you have" >> ${PREFIX}/etc/rc.d/rwhoisd.sh
	@ echo "# configured your server's data" >> ${PREFIX}/etc/rc.d/rwhoisd.sh
	@ echo "echo \"rwhoisd not started; sample data still in place.   See ${PREFIX}/share/doc/rwhois for details.\"" >> ${PREFIX}/etc/rc.d/rwhoisd.sh 
	@ echo "#[ -x /usr/local/lib/rwhois/sbin/rwhoisd ] && /usr/local/lib/rwhois/sbin/rwhoisd -c /usr/local/lib/rwhois/rwhois.conf & && echo -n ' rwhoisd'" >> ${PREFIX}/etc/rc.d/rwhoisd.sh
	chmod 751 ${PREFIX}/etc/rc.d/rwhoisd.sh

.include <bsd.port.mk>
