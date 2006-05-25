# Ports collection makefile for:	libsexy
# Date created:				2005-11-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=		libsexy
PORTVERSION=		0.1.8
CATEGORIES=		x11-toolkits devel
MASTER_SITES=		http://releases.chipx86.com/libsexy/libsexy/

MAINTAINER=		andreas@syndrom23.de
COMMENT=		Extension widgets for GTK+

BUILD_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=		enchant:${PORTSDIR}/textproc/enchant
RUN_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_GNOME=		gnomehack lthack gtk20 libxml2
INSTALLS_SHLIB=		yes
USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes

.include <bsd.port.mk>
