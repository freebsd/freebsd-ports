# $FreeBSD$

PORTNAME=	qtpass
PORTVERSION=	1.1.3
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	brouwer@annejan.com
COMMENT=	Qt GUI for pass, the standard unix password manager

LICENSE=	GPLv3

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

post-patch:
# The project file assumes PREFIX is the bin-dir. We pass PREFIX=${LOCALBASE}
# so we have to append bin to target.path.
	${REINPLACE_CMD} -e '/target.path/s,$$,bin,' ${WRKSRC}/qtpass.pro

# Install the icon of the port.
post-install:
	${INSTALL_DATA} ${WRKSRC}/artwork/icon.png \
			${STAGEDIR}${PREFIX}/share/pixmaps/qtpass.png

.include <bsd.port.mk>
