# New ports collection makefile for:    emovix
# Date created:                         2003/10/31
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	emovix
PORTVERSION=	0.9.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	movix

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A mini linux distro to create bootable video CDs

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_PERL5=	yes
USE_PERL5_BUILD=yes

.include <bsd.port.mk>
