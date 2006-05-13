# New ports collection makefile for:	amaya
# Date created:		26 Dec 1998
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	amaya
PORTVERSION=	9.2.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		http://ftp.uni-koeln.de/www/amaya/ \
		http://public.planetmirror.com/pub/amaya/ \
		ftp://ftp.uni-koeln.de/WWW/amaya/ \
		http://gd.tuwien.ac.at/infosys/browsers/amaya/ \
		http://ftp.ntua.gr/pub/www/W3C/amaya/ \
		ftp://ftp.ntua.gr/pub/www/W3C/amaya/ \
		ftp://nic.funet.fi/index/WWW/W3/amaya/ \
		http://www.nic.funet.fi/index/WWW/W3/amaya/
DISTNAME=	${PORTNAME}-fullsrc-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam-ports@blacktabby.org
COMMENT=	The W3C's testbed web editor/browser

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

FORBIDDEN=	http://www.vuxml.org/freebsd/dc930435-d59f-11da-8098-00123ffe8333.html

WRKSRC=		${WRKDIR}/Amaya/obj

USE_GMAKE=	yes
USE_GNOME=	gtk12 imlib
USE_ICONV=	yes

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=		--with-gtk

OPTIONS=	BOOKMARKS "Enable bookmark support (experimental)" off \
		OPENGL "Enable OpenGL support" off \
		TEMPLATES "Enable template support (experimental)" off

REALVERSION=	8.8.1
DATADIR=	${PREFIX}/Amaya-${REALVERSION}
PLIST_SUB=	REALVERSION="${REALVERSION}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not build on sparc64"
.endif

.if defined(WITH_BOOKMARKS)
CONFIGURE_ARGS+=	--enable-bookmarks
.else
CONFIGURE_ARGS+=	--disable-bookmarks
.endif

.if defined(WITH_OPENGL)
LIB_DEPENDS+=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
USE_GL=		yes
CONFIGURE_ARGS+=	--with-gl
CONFIGURE_ENV+=	LIBS="-lcompat"
PLIST_SUB+=	GUI="gl"
.else
PLIST_SUB+=	GUI="gtk"
.endif

.if defined(WITH_TEMPLATES)
CONFIGURE_ARGS+=	--enable-templates
.else
CONFIGURE_ARGS+=	--disable-templates
.endif

post-extract:
	@${MKDIR} ${WRKSRC}

post-patch:
	@${GREP} -lR "<malloc\.h>" ${WRKDIR} | \
		${XARGS} ${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g'

.include <bsd.port.post.mk>
