# New ports collection makefile for:	intltool
# Date created:				19th January 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	intltool
PORTVERSION=	0.25
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.25
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN8=		intltool-extract.8 intltool-merge.8 intltool-prepare.8 \
		intltool-update.8 intltoolize.8

.include <bsd.port.mk>
