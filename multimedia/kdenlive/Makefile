# New ports collection makefile for:	kdenlive
# Date created:				15 October 2008
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	kdenlive
PORTVERSION=	0.7.3
CATEGORIES=	multimedia kde
MASTER_SITES=	SFE

MAINTAINER=	villa.alberto@gmail.com
COMMENT=	A professional quality non-linear video editing suite for KDE

LIB_DEPENDS=	mlt.1:${PORTSDIR}/multimedia/mlt \
		mlt++.1:${PORTSDIR}/multimedia/mlt++

USE_GETTEXT=	yes
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix sharedmime
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui network svg xml \
		moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DNO_JOGSHUTTLE:BOOL=On
USE_LDCONFIG=	${PREFIX}/lib/kde4

PORTDOCS=	AUTHORS COPYING INSTALL README

MAN1=		kdenlive.1 kdenlive_render.1

OPTIONS=	LADSPA	"Install LADSPA plugins" on \
		SCREENGRAB	"Screen capture with recordMyDesktop" on

.include <bsd.port.pre.mk>

.ifdef(WITH_LADSPA)
RUN_DEPENDS+=	swhplugins>=0:${PORTSDIR}/audio/swhplugins
.endif

.ifdef(WITH_SCREENGRAB)
RUN_DEPENDS+=	recordmydesktop:${PORTSDIR}/multimedia/recordmydesktop
.endif

post-patch:
	# prevent updating mime during build
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
		${PATCH_WRKSRC}/src/mimetypes/CMakeLists.txt

post-install:
	@-update-mime-database ${PREFIX}/share/mime
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
