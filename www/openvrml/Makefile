# New ports collection makefile for:	OpenVRML
# Date created:				8 Jan 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openvrml
PORTVERSION=	0.14.3
PORTREVISION=	3
CATEGORIES=	www graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VRML97 runtime and browser ("lookat")

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/mozilla-js.pc:${PORTSDIR}/www/mozilla
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/mozilla-js.pc:${PORTSDIR}/www/mozilla

USE_REINPLACE=	yes
USE_GL=		yes
USE_MESA=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack
USE_GCC=	3.4
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lXext"
CONFIGURE_ARGS=	--without-jdk
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	# empty, not use * 'cause args too long (for find)
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.else
BROKEN=		"Does not build on i386"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure

post-install:
	@${FIND} ${PREFIX}/include/openvrml -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/openvrml -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/manual/ ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
