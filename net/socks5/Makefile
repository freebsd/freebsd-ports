# New ports collection makefile for:	socks5
# Version required:			v1.0r8
# Date created:				24 Apr 1996
# Whom:					pst
#
# $Id: Makefile,v 1.22 1999/01/06 03:59:14 obrien Exp $
#

DISTNAME=	socks5-v1.0r8
PKGNAME=	socks5-1.0.8
CATEGORIES=	net security
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

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libconffile=${PREFIX}/etc/libsocks5.conf \
		--with-srvconffile=${PREFIX}/etc/socks5.conf \
		--with-srvpidfile=/var/run/socks5.pid \
		--with-srvidtfile=/var/run/socks5.ident \
		${EXTRA_CONFIGURE_ARGS}
MAN1=		runsocks.1 socks5.1 stopsocks.1 socks5_clients.1
MAN5=		libsocks5.conf.5 socks5.conf.5

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	  ${ECHO} ""; \
	  ${ECHO} "NEC requires that you grab the dist files from their"; \
	  ${ECHO} "web site at http://www.socks.nec.com.  Please make sure"; \
	  ${ECHO} "you have ${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}"; \
	  ${ECHO} "and run make again."; \
	  ${ECHO} ""; \
	  exit 1;\
	fi

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
