# New ports collection makefile for:	libxml2
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	libxml2
PORTVERSION= 	2.2.4
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/libxml

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	iconv.1:${PORTSDIR}/converters/iconv

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--with-iconv
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -liconv"

MAN1=		xmllint.1
MAN4=		libxml.4

.include <bsd.port.mk>
