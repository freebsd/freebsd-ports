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

USES=		cmake kde:4 python:build tar:bzip2
USE_KDE=	automoc4
USE_QT4=	corelib dbus declarative qtestlib \
		moc_build qmake_build rcc_build uic_build
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

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e '/\.pc/ s|pkgconfig|../libdata/pkgconfig|' \
		-e 's|share/${PORTNAME}/cmake|lib/cmake/${PORTNAME}|' \
		-e "/add_subdirectory(tests)/ d" \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/src/CMakeLists.txt \
		${WRKSRC}/QZeitgeistConfig.cmake.in
	${REINPLACE_CMD} -e 's|zeitgeist.datamodel|datamodel|' \
		-e 's|env python|env ${PYTHON_CMD}|g' \
		${WRKSRC}/scripts/onto2cpp.py
.if ${PYTHON_VERSION:M*3*}
	${REINPLACE_CMD} -E -e '/except/ s|,| as |' \
		-e 's|(print) +>> +(sys\.stderr) *, *(.*)|\1(\3, file=\2)|' \
		-e 's|(print) +(.*)|\1(\2)|' \
		-e '/gettext\.install/ s|\((.*),.*\)|(\1)|' \
		-e 's|execfile\((.*)\)|exec(compile(open(\1, "rb").read(), \1, "exec"))|' \
		-e '/iter(items|keys|values)\(\)/ s|iter||g' \
		${WRKSRC}/scripts/*.py
.endif

.include <bsd.port.post.mk>
