# New ports collection makefile for:	OpenVRML
# Date created:				8 Jan 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openvrml
PORTVERSION=	0.15.9
CATEGORIES=	www graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VRML97 runtime and browser ("lookat")

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/mozilla-js.pc:${PORTSDIR}/www/mozilla	\
		${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone	\
		pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/mozilla-js.pc:${PORTSDIR}/www/mozilla

USE_REINPLACE=	yes
USE_GL=		yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gtk20
USE_SDL=	sdl
USE_GCC=	3.4
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -largp -Wl,--rpath -Wl,${X11BASE}/lib/mozilla -L${X11BASE}/lib -lXext" \
		XPIDLFLAGS="-I${X11BASE}/share/idl/mozilla"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

PLIST_SUB=	VER=${PORTVERSION}
SUB_FILES=	lookat.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on ${ARCH}"
.endif

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on ${OPSYS}-${OSREL}"
.endif

.if exists(${LOCALBASE}/include/boost/python.hpp)
LIB_DEPENDS+=	boost_python.2:${PORTSDIR}/devel/boost-python
.else
LIB_DEPENDS+=	boost_regex.2:${PORTSDIR}/devel/boost
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${SUB_FILES} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/manual/ ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
