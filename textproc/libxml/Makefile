# New ports collection makefile for:	libxml
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	libxml
PORTVERSION=	1.8.17
PORTREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/libxml/1.8

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Xml parser library for GNOME

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

pre-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

.include <bsd.port.mk>
