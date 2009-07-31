# New ports collection makefile for:	entropy
# Date created:		2006-08-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	entropyfm
PORTVERSION=	20080223
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
DISTNAME=	entropy-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An EFL-based file manager

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	ecore etk ewl evfs imlib2 epsilon
USE_EFL_ECORE=	config
GNU_CONFIGURE=	yes

CFLAGS+=	"-L${LOCALBASE}/lib"

OPTIONS=	XTRACT "Enable metadata extraction via libextractor" on \
		PNG	"Enable png thumbnailing" on

DATADIR=	${PREFIX}/share/entropy

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XTRACT)
LIB_DEPENDS+=	extractor.2:${PORTSDIR}/textproc/libextractor
CONFIGURE_ARGS+=--enable-plugin-extractor
PLIST_SUB+=	EXTRACT=""
.else
CONFIGURE_ARGS+=--disable-plugin-extractor
PLIST_SUB+=	EXTRACT="@comment "
.endif

.if !defined(WITHOUT_PNG) || exists(${LOCALBASE}/lib/libpng.so.5)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.endif

.include <bsd.port.post.mk>
