# $FreeBSD$

PORTNAME=	neochat
PORTVERSION=	0.1.0
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Glossy Matrix IM client based on KDE technologies

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

LIB_DEPENDS=	libcmark.so:textproc/cmark \
		libqt5keychain.so:security/qtkeychain
BUILD_DEPENDS=	libquotient>=0.6.2:net-im/libquotient

USES=		cmake compiler:c++17-lang gl kde:5 pkgconfig qt:5 tar:bz2
USE_GL=		gl
USE_QT=		core dbus declarative graphicaleffects gui imageformats \
		multimedia network quickcontrols quickcontrols2 \
		svg widgets xml \
		buildtools_build linguist_build qmake_build
USE_KDE=	config i18n kirigami2 notifications \
		ecm_build 

COMMIT=		1c6f1f7353dee450228d14a44f4d23968a4d890d
DISTFILES=	${PORTNAME}-${COMMIT}.tar.bz2:neochat
MASTER_SITES=	https://invent.kde.org/network/${PORTNAME}/-/archive/${COMMIT}/:neochat

# This is a hack before the first KDE release service release, since we're
# fetching GIT hashes rather than a tidy tarball.
WRKSRC=		${WRKDIR}/${PORTNAME}-${COMMIT}

.include <bsd.port.mk>
