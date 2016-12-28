# $FreeBSD$

PORTNAME=	qtpass
PORTVERSION=	1.1.6
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	brouwer@annejan.com
COMMENT=	Qt GUI for pass, the standard unix password manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pass:sysutils/password-store

USES=		qmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	IJhack
USE_QT5=	buildtools_build core gui linguisttools_build network widgets
USE_GL=		gl

PLIST_FILES=	bin/qtpass \
		share/pixmaps/qtpass.png

# Create a desktop entry for the port.
DESKTOP_ENTRIES=	"QtPass" "" \
			"${PREFIX}/share/pixmaps/qtpass.png" \
			"${PREFIX}/bin/qtpass" \
			"Security;Utility;" true

WRKSRC=		${WRKDIR}/QtPass-${PORTVERSION}

# Install the icon of the port.
post-install:
	${INSTALL_DATA} ${WRKSRC}/artwork/icon.png \
			${STAGEDIR}${PREFIX}/share/pixmaps/qtpass.png

.include <bsd.port.mk>
