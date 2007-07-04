# New ports collection makefile for:	OpenVRML
# Date created:				8 Jan 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openvrml
PORTVERSION=	0.15.10
PORTREVISION=	7
CATEGORIES=	www graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VRML97 runtime and browser ("lookat")

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mozilla-js.pc:${PORTSDIR}/www/mozilla	\
		${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone	\
		pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mozilla-js.pc:${PORTSDIR}/www/mozilla

USE_GL=		yes
USE_GNOME=	gnomehack gtk20
USE_SDL=	sdl
USE_GCC=	3.4
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -largp -Wl,--rpath -Wl,${LOCALBASE}/lib/mozilla -L${X11BASE}/lib -lXext" \
		XPIDLFLAGS="-I${LOCALBASE}/share/idl/mozilla"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	VER=${PORTVERSION}
SUB_FILES=	lookat.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700029
BROKEN=		Incorrect objformat handling
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Gets internal gcc error on ${ARCH}
.endif

.if exists(${LOCALBASE}/include/boost/python.hpp)
LIB_DEPENDS+=	boost_python.4:${PORTSDIR}/devel/boost-python
.else
LIB_DEPENDS+=	boost_regex.4:${PORTSDIR}/devel/boost
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${SUB_FILES} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/manual/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/models/*.wrl ${EXAMPLESDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.if defined(MAINTAINER_MODE)
test:	build
	(cd ${WRKSRC}/tests ;	\
	./testsuite )
.endif

.include <bsd.port.post.mk>
