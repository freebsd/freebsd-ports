# ex:ts=8
# Ports collection makefile for:	pslib
# Date created:			Jul 13, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pslib
PORTVERSION=	0.2.6
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C-library for generating multi page PostScript documents

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnomehack gnometarget intlhack pkgconfig
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		ac_cv_prog_DOC_TO_MAN=""
INSTALLS_SHLIB=	yes

.if defined(WITHOUT_NLS)
CONFIGURE_ENV+=	ac_cv_header_libintl_h=no
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
