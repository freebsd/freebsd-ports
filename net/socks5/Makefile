# New ports collection makefile for:	socks5
# Version required:			beta-0.17.1-exportable
# Date created:				24 Apr 1996
# Whom:					pst
#
# $Id: Makefile,v 1.9 1996/11/18 14:09:01 asami Exp $
#

PKGNAME=	socks5-0.17.1
DISTNAME=	socks5-beta-0.17.1-exportable
CATEGORIES=	net security
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
MAN1=		runsocks.1 socks5.1 stopsocks.1
MAN5=		libsocks5.conf.5 socks5.conf.5

.include <bsd.port.mk>
