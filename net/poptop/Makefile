# New ports collection makefile for:	poptop
# Date created:		04 October 1999
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		poptop
PORTVERSION=		1.1.4.b4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	poptop
DISTNAME=		pptpd-${PORTVERSION:S/.b/-b/}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Windows 9x compatible PPTP (VPN) server

GNU_CONFIGURE=		yes
.ifdef(POPTOP_KERNPPP)
CONFIGURE_ARGS=
.else
CONFIGURE_ARGS=		--with-bsdppp
.endif
WRKSRC=			${WRKDIR}/${PORTNAME}-1.1.4

MAN5=			pptpd.conf.5
MAN8=			pptpd.8 pptpctrl.8

# fix broken timestamps that trigger autotools hell
pre-patch:
	@cd ${WRKSRC}; ${TOUCH} aclocal.m4 Makefile.in stamp-h.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/pptpd.conf \
		${PREFIX}/etc/pptpd.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pptpd.sh \
		${PREFIX}/etc/rc.d/pptpd.sh.sample

.include <bsd.port.mk>
