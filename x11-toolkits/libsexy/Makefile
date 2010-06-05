# New ports collection makefile for:	libsexy
# Date created:				2005-11-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	libsexy
PORTVERSION=	0.1.11
PORTREVISION=	5
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://releases.chipx86.com/libsexy/libsexy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extension widgets for GTK+

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	enchant:${PORTSDIR}/textproc/enchant
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_AUTOTOOLS=	libtool:22
USE_GETTEXT=	yes
USE_GNOME=	gnomehack lthack gtk20 libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
