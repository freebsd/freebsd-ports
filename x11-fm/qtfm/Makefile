PORTNAME=	qtfm
PORTVERSION=	6.2.1
PORTREVISION=	1
CATEGORIES=	x11-fm

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Small, lightweight file manager based on pure Qt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5
USE_GL=		gl
USE_QT=		concurrent core dbus gui widgets \
		buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	rodlie

QMAKE_ARGS=	MANDIR=${PREFIX}/share/man \
		PREFIX=${PREFIX} \
		XDGDIR=${PREFIX}/etc/xdg \
		DOCDIR=${DOCSDIR}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|docs.path.*|docs.path = $$$${DOCDIR}|' \
		${WRKSRC}/libfm/libfm.pro

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qtfm

.include <bsd.port.mk>
