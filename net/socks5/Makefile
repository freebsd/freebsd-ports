# New ports collection makefile for:	socks5
# Version required:			beta-0.16.6
# Date created:				24 Apr 1996
# Whom:					pst
#
# $Id: Makefile,v 1.6 1996/08/14 16:02:42 jdp Exp $
#

PKGNAME=	socks5-0.16.6
DISTNAME=	socks5-beta-0.16.6-exportable
CATEGORIES+=	net security
MASTER_SITES=	ftp://ftp.nec.com/pub/socks/socks5/

MAINTAINER=	ambrisko@ambrisko.roble.com

NO_CDROM=	NEC has a funky license for this software
RESTRICTED=	no commercial use
NO_PACKAGE=	put an extra slug in to make sure he's dead

# here are some extra configure args you may wish to use
# see the readme file before screwing with them
#
#EXTRA_CONFIGURE_ARGS= \
#		--with-default-server=socks.mydomain.com \
#		--with-syslog-facility=LOG_AUTH \
#		--with-passwd

GNU_CONFIGURE=	yes
CONFIGURE_ENV=  LIBS=-lcrypt
CONFIGURE_ARGS=	--with-libconffile=${PREFIX}/etc/libsocks5.conf \
		--with-srvconffile=${PREFIX}/etc/socks5.conf \
		--with-srvpidfile=/var/run/socks5.pid \
		--with-srvidtfile=/var/run/socks5.ident \
		${EXTRA_CONFIGURE_ARGS}

.include <bsd.port.mk>
