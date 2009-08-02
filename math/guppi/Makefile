# New ports collection makefile for:	guppi
# Date created:				22 December 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guppi
PORTVERSION=	0.40.3
PORTREVISION=	14
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/Guppi/0.40
DISTNAME=	Guppi-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A plotting program for GNOME

LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs bonobo libglade gal gnometarget
USE_PYTHON=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gnumeric --enable-explicit-python-linking
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/libglade-1.0" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		GNUMERIC_IDLDIR="${WRKDIR}/gnumeric"
PLIST_SUB=	VERSION="${PORTVERSION}"
.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/gnumeric
	@${CP} ${FILESDIR}/GNOME_Gnumeric_Graph.idl ${WRKDIR}/gnumeric

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
		${WRKSRC}/configure \
		${WRKSRC}/aclocal.m4

post-install:
	@${RMDIR} ${LOCALBASE}/share/gnome/help/guppi/C/images

.include <bsd.port.mk>
