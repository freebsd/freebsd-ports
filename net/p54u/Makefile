# Ports collection makefile for:	p54u
# Date created:				20 January 2006
# Whom:					Sebastien Bourdeauducq <lekernel@prism54.org>
#
# $FreeBSD$
#

PORTNAME=	p54u
PORTVERSION=	0.8
CATEGORIES=	net kld
MASTER_SITES=	http://www.prism54.org/p54u/releases/

MAINTAINER=	lekernel@prism54.org
COMMENT=	Driver for USB wireless devices with Conexant (Prism 54) chipsets

NO_PACKAGE=	Should be in sync with the kernel to work correctly

USE_BZIP2=	yes
MANCOMPRESSED=	yes

MAN4=		p54u.4
MAN8=		p54ctl.8 p54term.8

.if !exists(/usr/src/sys/dev/usb/usb.h)
IGNORE=		requires kernel source (/usr/src/sys) to build
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		is not supported on FreeBSD 5.X and older
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
