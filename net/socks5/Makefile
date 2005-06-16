# New ports collection makefile for:	socks5
# Date created:				24 Apr 1996
# Whom:					pst
#
# $FreeBSD$
#

PORTNAME=	socks5
PORTVERSION=	1.0.11
PORTREVISION=	3
CATEGORIES=	net security
MASTER_SITES=	http://freeware.sgi.com/source/socks5/
DISTNAME=	socks5-v1.0r11

MAINTAINER=	josh@tcbug.org
COMMENT=	SOCKS v5 application layer gateway and clients

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
		--with-srvpwdfile=${PREFIX}/etc/socks5.passwd \
		${EXTRA_CONFIGURE_ARGS}
MAN1=		runsocks.1 socks5.1 stopsocks.1 socks5_clients.1
MAN5=		libsocks5.conf.5 socks5.conf.5 socks5.passwd.5
CONFIGURE_ENV=	LIBS=-lcrypt

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/socks5.sh ]; then \
		${ECHO} "Creating ${PREFIX}/etc/rc.d/socks5.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/socks5.sh.sample ${PREFIX}/etc/rc.d/socks5.sh; \
	 fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
