# New ports collection makefile for:	intltool
# Date created:				19th January 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	intltool
PORTVERSION=	0.15
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/${PORTNAME}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

MAN8=		intltool-extract.8 intltool-merge.8 intltool-prepare.8 \
		intltoolize.8

pre-patch:
	@find ${WRKSRC} -name "intltool-*.in" | xargs ${PERL} -pi -e \
		's|iconv -|giconv -|g'

.include <bsd.port.mk>
