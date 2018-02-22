# $FreeBSD$

PORTNAME=	qtpass
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	sysutils

MAINTAINER=	brouwer@annejan.com
COMMENT=	Qt GUI for pass, the standard unix password manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pass:sysutils/password-store

USES=		qmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	IJhack
GH_PROJECT=	QtPass
USE_QT5=	core gui network testlib widgets buildtools_build linguisttools_build
USE_GL=		gl

PLIST_FILES=	bin/qtpass \
		share/pixmaps/qtpass.png \
		${QT_TESTDIR}/qtpass/util/tst_util

# Create a desktop entry for the port.
DESKTOP_ENTRIES=	"QtPass" "" \
			"${PREFIX}/share/pixmaps/qtpass.png" \
			"${PREFIX}/bin/qtpass" \
			"Security;Utility;" true

# Install the icon of the port.
post-install:
	${INSTALL_DATA} ${WRKSRC}/artwork/icon.png \
			${STAGEDIR}${PREFIX}/share/pixmaps/qtpass.png

.include <bsd.port.mk>
