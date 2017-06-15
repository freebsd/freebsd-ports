# Created by: haikal
# $FreeBSD$

PORTNAME=	gnewtellium
PORTVERSION=	0.05b
PORTREVISION=	6
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Gnutella client

PORTSCOUT=	skipv:0.05	# older than current one

USE_GNOME=	gtk12
USES=		dos2unix gmake
DOS2UNIX_GLOB=	*.c
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

PLIST_FILES=	bin/gnewtellium %%DATADIR%%/pixmaps/gnewtellium.xpm

.include <bsd.port.mk>
