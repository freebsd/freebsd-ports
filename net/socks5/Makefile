# New ports collection makefile for:	socks5
# Version required:			v1.0r3
# Date created:				24 Apr 1996
# Whom:					pst
#
# $Id: Makefile,v 1.14 1997/08/28 06:49:06 obrien Exp $
#

DISTNAME=	socks5-v1.0r3
PKGNAME=	socks5-1.0.3
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.astec.co.jp/pub/security/socks/  \
		ftp://ftp.ualg.pt/Linux/net/proxies/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	imp@freebsd.org

NO_CDROM=	"NEC has a funky license for this software"
RESTRICTED=	"no commercial use"

# here are some extra configure args you may wish to use
# see the readme file before screwing with them
#
#EXTRA_CONFIGURE_ARGS= \
#		--with-default-server=socks.mydomain.com \
#		--with-syslog-facility=LOG_AUTH \
#		--with-passwd

WRKSRC=		${WRKDIR}/socks5-v1.0r3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libconffile=${PREFIX}/etc/libsocks5.conf \
		--with-srvconffile=${PREFIX}/etc/socks5.conf \
		--with-srvpidfile=/var/run/socks5.pid \
		--with-srvidtfile=/var/run/socks5.ident \
		${EXTRA_CONFIGURE_ARGS}
MAN1=		runsocks.1 socks5.1 stopsocks.1 socks5_clients.1
MAN5=		libsocks5.conf.5 socks5.conf.5

.include <bsd.port.mk>

# the following need to be included after bsd.port.mk, since OPSYS
# ARCH are defined in bsd.port.mk

.if ${OPSYS} == "FreeBSD"
CONFIGURE_ENV=  LIBS=-lcrypt
.endif

# OpenBSD/arc doesn't seem to have a working ldconfig

.if ${OPSYS} != "OpenBSD" || ${ARCH} != "arc"
post-install:
	ldconfig -m ${PREFIX}/lib
.endif
