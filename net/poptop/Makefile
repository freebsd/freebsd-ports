# New ports collection makefile for:	poptop
# Date created:		04 October 1999
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		poptop
PORTVERSION=		1.1.3
PORTREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	poptop
DISTNAME=		pptpd-${PORTVERSION}

MAINTAINER=		ports@freebsd.org

PORTCOMMENT=		Windows 9x compatible PPTP (VPN) server

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-bsdppp

MAN5=			pptpd.conf.5
MAN8=			pptpd.8 pptpctrl.8

pre-patch:
	${RM} ${WRKSRC}/config.cache
	${CP} ${WRKSRC}/our_getopt.h ${WRKSRC}/getopt.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/pptpd.conf \
		${PREFIX}/etc/pptpd.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pptpd.sh \
		${PREFIX}/etc/rc.d/pptpd.sh.sample

.include <bsd.port.mk>
