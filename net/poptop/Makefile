# New ports collection makefile for:	poptop
# Version required:	1.0.0
# Date created:		04 October 1999
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	pptpd-1.0.0
PKGNAME=	poptop-1.0.0
CATEGORIES=	net
MASTER_SITES=	http://www.moretonbay.com/vpn/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nsayer@freebsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bsdppp

MAN5=		pptpd.conf.5
MAN8=		pptpd.8 pptpctrl.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/pptpd.conf ${PREFIX}/etc/pptpd.conf.sample
	${INSTALL_DATA} ${FILESDIR}/pptpd.sh ${PREFIX}/etc/rc.d/pptpd.sh

.include <bsd.port.mk>
