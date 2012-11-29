# Created by: Bas Kruit <baskruit@bsltwr.dnsalias.org>
# $FreeBSD$

PORTNAME=	gmime
PORTVERSION=	1.0.8
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://spruce.sourceforge.net/gmime/sources/v1.0/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library (written in C) for parsing and creating messages using MIME

CONFLICTS=	gmime-2.1.*
USE_AUTOTOOLS=	libtool
USE_GMAKE=	YES
USE_GNOME=	glib12
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-L${LOCALBASE}/lib # req'd to find iconv
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS=	confexecdir=${PREFIX}/etc

USE_LDCONFIG=	yes

DEPRECATED=	Superceded with version 2.4
EXPIRATION_DATE=	2013-02-28

.include <bsd.port.mk>
