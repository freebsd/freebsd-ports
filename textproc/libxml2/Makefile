# New ports collection makefile for:	libxml2
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	libxml2
PORTVERSION= 	2.2.3
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/libxml

MAINTAINER=	ade@FreeBSD.org

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--without-iconv
INSTALLS_SHLIB=	yes

MAN1=		xmllint.1
MAN4=		libxml.4

.include <bsd.port.mk>
