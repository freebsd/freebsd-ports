# Ports collection makefile for:  Dante
# Date created:			  20 October 1999
# Whom:				  Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	dante
PORTVERSION=	1.1.13
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.inet.no/pub/socks/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	anders@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-socks-conf=${PREFIX}/etc/socks.conf \
		--with-sockd-conf=${PREFIX}/etc/sockd.conf

INSTALLS_SHLIB=	yes

MAN5=	sockd.conf.5 socks.conf.5
MAN8=	sockd.8

post-install:
	@${INSTALL_DATA} ${WRKSRC}/example/socks.conf ${PREFIX}/etc/socks.conf.example
	@${INSTALL_DATA} ${WRKSRC}/example/sockd.conf ${PREFIX}/etc/sockd.conf.example
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 555 ${PREFIX}/share/doc/dante
	@${INSTALL_DATA} ${WRKSRC}/doc/README* ${PREFIX}/share/doc/dante
	@${INSTALL_DATA} ${WRKSRC}/doc/rfc* ${PREFIX}/share/doc/dante
	@${INSTALL_DATA} ${WRKSRC}/doc/SOCKS4.protocol ${PREFIX}/share/doc/dante
	@${INSTALL_DATA} ${WRKSRC}/doc/faq.tex ${PREFIX}/share/doc/dante
.endif

.include <bsd.port.mk>
