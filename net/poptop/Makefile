# New ports collection makefile for:	poptop
# Date created:		04 October 1999
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	poptop
PORTVERSION=	1.0.1
CATEGORIES=	net
MASTER_SITES=	http://poptop.lineo.com/releases/
DISTNAME=	pptpd-${PORTVERSION}

MAINTAINER=	nsayer@freebsd.org

FORBIDDEN=	"This port is deprecated in favor of ports/net/mpd-netgraph's pptp functionality"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bsdppp

MAN5=		pptpd.conf.5
MAN8=		pptpd.8 pptpctrl.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/pptpd.conf ${PREFIX}/etc/pptpd.conf.sample
	${INSTALL_DATA} ${FILESDIR}/pptpd.sh ${PREFIX}/etc/rc.d/pptpd.sh

.include <bsd.port.mk>
