# ex:ts=8
# New ports collection makefile for:	gsk
# Date created:			May 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gsk
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C library for writing servers

BROKEN=		Does not build

USE_GNOME=	glib20 gnomehack gnometarget
USE_PERL5=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=	--disable-gtk-doc
INSTALLS_SHLIB=	yes

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--disable-ssl
PLIST_SUB+=	OPENSSL="@comment "
.else
USE_OPENSSL=	yes
PLIST_SUB+=	OPENSSL=""
.endif

.include <bsd.port.mk>
