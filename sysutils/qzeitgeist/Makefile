# $FreeBSD$

PORTNAME=	qzeitgeist
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	KDE/stable/lib${PORTNAME}/${PORTVERSION}/src/:kde \
		http://launchpad.net/zeitgeist/${ZEITGEIST_VERSION:R}/${ZEITGEIST_VERSION}/+download/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:kde \
		zeitgeist-${ZEITGEIST_VERSION}.tar.xz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Qt 4 wrapper library around the Zeitgeist D-Bus API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rapper:textproc/raptor2 \
		${PYTHON_SITELIBDIR}/rdflib/__init__.py:textproc/py-rdflib

USE_KDE4=	automoc4
USE_QT4=	dbus declarative qtestlib \
		moc_build qmake_build rcc_build uic_build
USES=		cmake python:build tar:bzip2
USE_LDCONFIG=	yes

# To be kept in sync with sysutils/zeitgeist.
ZEITGEIST_VERSION=	0.9.16

post-extract:
	@(cd ${WRKDIR} && ${TAR} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/zeitgeist-${ZEITGEIST_VERSION}.tar.xz \
		${EXTRACT_AFTER_ARGS})
	cd ${WRKDIR}/zeitgeist-${ZEITGEIST_VERSION} && \
		${CP} -r python/*.py \
			data/ontology \
			${WRKSRC}/scripts

post-patch:
	${REINPLACE_CMD} -e '/\.pc/ s|pkgconfig|../libdata/pkgconfig|' \
		-e 's|share/${PORTNAME}/cmake|lib/cmake/${PORTNAME}|' \
		-e "/add_subdirectory(tests)/ d" \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/src/CMakeLists.txt \
		${WRKSRC}/QZeitgeistConfig.cmake.in
	${REINPLACE_CMD} -e 's|zeitgeist.datamodel|datamodel|' \
		${WRKSRC}/scripts/onto2cpp.py
	${REINPLACE_CMD} -e 's|env python|env ${PYTHON_CMD}|g' \
		${WRKSRC}/scripts/onto2cpp.py

.include <bsd.port.mk>
