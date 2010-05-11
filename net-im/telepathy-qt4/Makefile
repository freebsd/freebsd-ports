# New ports collection Makefile for:	telepathy-qt4
# Date created:				14 January 2010
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	telepathy-qt4
PORTVERSION=	0.3.2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	High-level Qt 4 binding for Telepathy

LIB_DEPENDS=	telepathy-farsight.0:${PORTSDIR}/net-im/telepathy-farsight \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_GNOME=	pkgconfig
USE_PYTHON_BUILD=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus network xml qtestlib_build \
		moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO html

PORTEXAMPLES=	Makefile accounts call extensions \
		file-transfer protocols roster

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
BROKEN=		does not build on 6.X
.endif

pre-configure:
	@${REINPLACE_CMD} -E -e 's:(^pkgconfigdir =).*:\1 ${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/TelepathyQt4/Makefile.in

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
	${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
