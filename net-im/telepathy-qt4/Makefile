# New ports collection Makefile for:	telepathy-qt4
# Date created:				14 January 2010
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	telepathy-qt4
PORTVERSION=	0.4.2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	High-level Qt 4 binding for Telepathy

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	telepathy-farsight.0:${PORTSDIR}/net-im/telepathy-farsight \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_GNOME=	pkgconfig
USE_PYTHON_BUILD=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus network xml qtestlib_build \
		moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog HACKING NEWS README TODO html

PORTEXAMPLES=	Makefile accounts extensions \
		file-transfer protocols roster

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
BROKEN=		does not build on 6.X
.endif

pre-configure:
	${REINPLACE_CMD} -e '/add_subdirectory(tests)/ d' \
		${WRKSRC}/CMakeLists.txt
.ifdef(NOPORTEXAMPLES)
	${REINPLACE_CMD} -e '/add_subdirectory(examples)/ d' \
		${WRKSRC}/CMakeLists.txt
.endif
	${REINPLACE_CMD} -e '/TelepathyQt4.*\.pc/ s|pkgconfig|../libdata/pkgconfig|' \
		${WRKSRC}/TelepathyQt4/CMakeLists.txt
	${REINPLACE_CMD} -e '/$${LIBXML2_INCLUDE_DIR}/ s|$$| ${LOCALBASE}/include|' \
		${WRKSRC}/TelepathyQt4/Farsight/CMakeLists.txt

pre-install:
.ifndef(NOPORTDOCS)
	cd ${WRKSRC} && ${CP} -R doc/html .
.endif

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${DOCSDIR}
.endfor
.endif
.ifndef(NOPORTEXAMPLES)
	cd ${WRKSRC}/examples && ${RM} -rf */CMakeFiles */*.cmake */Makefile
	${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
