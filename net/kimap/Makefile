# $FreeBSD$

PORTNAME=	kimap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE API for IMAP support

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libsasl2.so:security/cyrus-sasl2

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	codecs config coreaddons ecm i18n kdelibs4support kio service
# pim components
USE_KDE+=	mime
USE_QT=		core \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
