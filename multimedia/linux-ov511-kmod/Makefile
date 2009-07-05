# New ports collection makefile for:	linux-ov511-kmod
# Date created:				2 February 2007
# Whom:					luigi
#
# $FreeBSD$
#
# XXX MASTER_SITES should be replaced with some good locations
# for individual files from linux distributions.

PORTNAME=	linux-ov511-kmod
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	multimedia kld
MASTER_SITES=	http://info.iet.unipi.it/~luigi/FreeBSD/linux/drivers/media/video/
DISTFILES=	ov511.c ov511.h
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	luigi@FreeBSD.org
COMMENT=	A port of the linux ov511 webcam driver

# Requires the linux emulation layer to be built
BUILD_DEPENDS=	/usr/share/mk/bsd.linux_kmod.mk:${PORTSDIR}/devel/linux-kmod-compat

NO_PACKAGE=	depends on kernel sources

# This is our Makefile to be used for build/install.
MAKEFILE=	Makefile.kld
ALL_TARGET=	depend all

# we simply copy the sources from the original site
do-extract:
	@${MKDIR} ${WRKSRC}
	( cd ${_DISTDIR} && ${CP} ${DISTFILES} ${WRKSRC} )

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

.include <bsd.port.mk>
