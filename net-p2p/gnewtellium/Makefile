# Created by: haikal
# $FreeBSD$

PORTNAME=	gnewtellium
PORTVERSION=	0.05b
PORTREVISION=	5
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Gnutella client

PORTSCOUT=	skipv:0.05	# older than current one

USE_GNOME=	gtk12
USES=		gmake
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

PLIST_FILES=	bin/gnewtellium %%DATADIR%%/pixmaps/gnewtellium.xpm
PLIST_DIRS=	%%DATADIR%%/pixmaps %%DATADIR%%

.include <bsd.port.mk>
