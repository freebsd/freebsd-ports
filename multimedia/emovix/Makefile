# New ports collection makefile for:    k3b
# Date created:                         2003/10/31
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	emovix
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	movix

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A mini linux distro to create bootable video CDs

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Configure fails"
.endif

.include <bsd.port.post.mk>
