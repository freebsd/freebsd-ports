# $FreeBSD$

PORTNAME=	qzeitgeist
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_KDE:C@$@:kde@} \
		http://launchpad.net/zeitgeist/${ZEITGEIST_VERSION:R}/${ZEITGEIST_VERSION}/+download/
MASTER_SITE_SUBDIR=	stable/lib${PORTNAME}/${PORTVERSION}/src/:kde
DISTNAME=	lib${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:kde \
		zeitgeist-${ZEITGEIST_VERSION}.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Qt 4 wrapper library around the Zeitgeist D-Bus API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rapper:${PORTSDIR}/textproc/raptor2 \
		${PYTHON_SITELIBDIR}/rdflib/__init__.py:${PORTSDIR}/textproc/py-rdflib

USE_KDE4=	automoc4
USE_PYTHON_BUILD=	yes
USE_QT4=	dbus declarative qtestlib \
		moc_build qmake_build rcc_build uic_build
USES=		tar:bzip2 cmake
USE_LDCONFIG=	yes

# To be kept in sync with sysutils/zeitgeist.
ZEITGEIST_VERSION=	0.8.2

post-extract:
	@(cd ${WRKDIR} && ${TAR} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/zeitgeist-${ZEITGEIST_VERSION}.tar.gz \
		${EXTRACT_AFTER_ARGS})
	cd ${WRKDIR}/zeitgeist-${ZEITGEIST_VERSION} && \
		${CP} zeitgeist/datamodel.py \
			extra/ontology/*.trig \
			extra/rdfxml2py \
			extra/PythonSerializer.py \
			${WRKSRC}/scripts

post-patch:
	${REINPLACE_CMD} -e '/\.pc/ s|pkgconfig|../libdata/pkgconfig|' \
		-e 's|share/${PORTNAME}/cmake|lib/cmake/${PORTNAME}|' \
		-e "/add_subdirectory(tests)/ d" \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/src/CMakeLists.txt \
		${WRKSRC}/QZeitgeistConfig.cmake.in
	${REINPLACE_CMD} -e '/import _config/ d' \
		-e 's|_config.datadir, "zeitgeist/ontology/zeitgeist.py"|runpath, "zeitgeist.py"|' \
		${WRKSRC}/scripts/datamodel.py
	${REINPLACE_CMD} -e 's|zeitgeist.datamodel|datamodel|' \
		${WRKSRC}/scripts/onto2cpp.py
	${REINPLACE_CMD} -e 's|env python|env ${PYTHON_CMD}|g' \
		${WRKSRC}/scripts/onto2cpp.py
	${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/scripts/rdfxml2py

pre-build:
	cd ${WRKSRC}/scripts && \
		${CAT} *.trig | \
		${LOCALBASE}/bin/rapper -i trig -o rdfxml -I ZeitgeistNamespace - | \
		./rdfxml2py >> zeitgeist.py

.include <bsd.port.mk>
