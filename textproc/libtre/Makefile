# ex:ts=8
# Ports collection makefile for:	libtre
# Date created:			Oct 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libtre
PORTVERSION=	0.6.6
CATEGORIES=	textproc
MASTER_SITES=	http://laurikari.net/tre/
DISTNAME=	tre-${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	A lightweight fully POSIX compliant regexp matching library

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig lthack
USE_GETOPT_LONG=	yes
USE_LIBTOOL_VER=	13
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -lintl

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
