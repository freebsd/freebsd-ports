# Ports collection makefile for:  Dante
# Date created:			  20 October 1999
# Whom:				  Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	dante
PORTVERSION=	1.1.15
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.inet.no/pub/socks/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A circuit-level firewall/proxy

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-socks-conf=${PREFIX}/etc/socks.conf \
		--with-sockd-conf=${PREFIX}/etc/sockd.conf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

INSTALLS_SHLIB=	yes

MAN5=	sockd.conf.5 socks.conf.5
MAN8=	sockd.8

post-install:
	@${INSTALL_DATA} ${WRKSRC}/example/socks.conf ${PREFIX}/etc/socks.conf.example
	@${INSTALL_DATA} ${WRKSRC}/example/sockd.conf ${PREFIX}/etc/sockd.conf.example
	@${INSTALL_SCRIPT} ${FILESDIR}/sockd.sh ${PREFIX}/etc/rc.d/sockd.sh-dist
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 555 ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/README* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/rfc* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/SOCKS4.protocol ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/faq.tex ${DOCSDIR}
.endif

.include <bsd.port.mk>
