# New ports collection makefile for:	socks5
# Date created:				24 Apr 1996
# Whom:					pst
#
# $FreeBSD$
#

PORTNAME=	socks5
PORTVERSION=	1.0.11
PORTREVISION=	1
CATEGORIES=	net security
DISTNAME=	socks5-v1.0r11

MAINTAINER=	ports@freebsd.org

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
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libconffile=${PREFIX}/etc/libsocks5.conf \
		--with-srvconffile=${PREFIX}/etc/socks5.conf \
		--with-srvpidfile=/var/run/socks5.pid \
		--with-srvidtfile=/var/run/socks5.ident \
		${EXTRA_CONFIGURE_ARGS}
MAN1=		runsocks.1 socks5.1 stopsocks.1 socks5_clients.1
MAN5=		libsocks5.conf.5 socks5.conf.5
CONFIGURE_ENV=  LIBS=-lcrypt

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE="NEC requires that you grab the dist files from their web site at http://www.socks.nec.com/cgi-bin/download.pl .  Please make sure you have ${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR} and run make again."
.endif

.include <bsd.port.mk>
