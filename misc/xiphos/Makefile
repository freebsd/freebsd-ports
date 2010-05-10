# New ports collection makefile for: xiphos
# Date created:   February 2, 2009
# Whom:           Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xiphos
PORTVERSION=	3.1.3
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	SF/gnomesword/Xiphos/${PORTVERSION}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A bible interface utilizing the sword framework

RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.6.1.so:${PORTSDIR}/misc/sword
BUILD_DEPENDS=	${RUN_DEPENDS} \
		gnome-doc-tool:${PORTSDIR}/textproc/gnome-doc-utils \
		nspr>=4.8:${PORTSDIR}/devel/nspr

USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gnomelibs gtkhtml3 \
		intlhack libgsf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/nspr" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--disable-maintainer-mode

OPTIONS=	LIBXUL  "Build with libxul" on \
		GTKHTML	"Build with gtkhtml" off \

.include <bsd.port.pre.mk>

.if defined(WITH_LIBXUL) && defined(WITH_GTKHTML)
IGNORE=		choose only one of LIBXUL or GTKHTML
.endif

.if defined(WITH_GTKHTML) || defined(WITHOUT_LIBXUL)
CONFIGURE_ARGS+=	--without-gecko
.endif

.if !defined(WITHOUT_LIBXUL) || !defined(WITH_GTKHTML)
USE_GECKO=	libxul
CONFIGURE_ARGS+=	--with-gecko=${GECKO} --with-gecko-home=${LOCALBASE}/lib/libxul
.endif

.include <bsd.port.post.mk>
