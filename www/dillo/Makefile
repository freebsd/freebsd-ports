# New ports collection makefile for:   dillo
# Date created:        23 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       dillo
PORTVERSION=	0.4.0
CATEGORIES=     www
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	greid@ukug.uk.freebsd.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		intl.1:${PORTSDIR}/devel/gettext

USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib"
USE_GMAKE=	yes

.include <bsd.port.mk>
