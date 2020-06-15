# $FreeBSD$

PORTNAME=	spectral
PORTVERSION=	817
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Glossy Matrix IM client based on Qt technologies

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain \
		libcmark.so:textproc/cmark

USES=		cmake compiler:c++17-lang gl pkgconfig qt:5 tar:bz2
USE_GL=		gl
USE_QT=		core dbus declarative graphicaleffects gui imageformats \
		multimedia network quickcontrols quickcontrols2 svg widgets \
		buildtools_build linguist_build qmake_build

CMAKE_ON=	USE_INTREE_LIBQMC

SFPMNAME=	SortFilterProxyModel
SFPMVERSION=	36befddf5d57faad990e72c88c5844794f274145
QUOTNAME=	libQuotient
QUOTVERSION=	58dfe74390ebdd8ec6611d3b8fecfe7d051ff955
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2:spectral \
		${SFPMVERSION}.zip:sfpm \
		${QUOTVERSION}.zip:quot
MASTER_SITES=	https://gitlab.com/spectral-im/spectral/-/archive/${PORTVERSION}/:spectral \
		https://github.com/oKcerG/${SFPMNAME}/archive/:sfpm \
		https://github.com/quotient-im/${QUOTNAME}/archive/:quot


post-extract:
	${RMDIR} ${WRKSRC}/include/${SFPMNAME} ${WRKSRC}/include/${QUOTNAME}
	${LN} -s ${WRKDIR}/${SFPMNAME}-${SFPMVERSION} ${WRKSRC}/include/${SFPMNAME}
	${LN} -s ${WRKDIR}/${QUOTNAME}-${QUOTVERSION} ${WRKSRC}/include/${QUOTNAME}

.include <bsd.port.mk>
