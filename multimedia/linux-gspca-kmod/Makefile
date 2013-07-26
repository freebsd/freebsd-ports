# New ports collection makefile for:	gspcav1-kmod
# Date created:				1 February 2007
# Whom:					luigi
#
# $FreeBSD$
#

PORTNAME=	linux-gspca-kmod
PORTVERSION=	1.0.20
PORTREVISION=	1
CATEGORIES=	multimedia kld
MASTER_SITES=	http://mxhaard.free.fr/spca50x/Download/oldrelease/
DISTNAME=	gspcav1-20071220

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A port of the linux gspcav1 webcam driver

# Requires the linux emulation layer to be built
BUILD_DEPENDS=	/usr/share/mk/bsd.linux_kmod.mk:${PORTSDIR}/devel/linux-kmod-compat

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27

NO_PACKAGE=	depends on kernel sources

# This is our Makefile to be used for build/install.
MAKEFILE=	Makefile.kld
ALL_TARGET=	depend all

.include <bsd.port.pre.mk>

BROKEN=		does not compile on 8.X

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

.include <bsd.port.post.mk>
