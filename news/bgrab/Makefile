# New ports collection makefile for:	bgrab
# Version required:	1.2.3
# Date created:		27 July 1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

DISTNAME=	bgrab
PKGNAME=	bgrab-1.2.3
CATEGORIES=	news
MASTER_SITES=	http://thelamb.dhs.org/~rael/bgrab/ \
		http://awwm.linuxberg.com/files/console/network/ \
		http://powerlinux.linuxberg.com/files/console/network/

MAINTAINER=	kbyanc@posi.net

RUN_DEPENDS=	mmencode:${PORTSDIR}/converters/mmencode

post-extract:
	@${CP} ${FILESDIR}/Makefile.dist ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bgrab ${PREFIX}/bin

.include <bsd.port.mk>
