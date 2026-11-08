PORTNAME=	libsysstat
PORTVERSION=	0.4.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Library used to query system info and statistics
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses qt5 switch to qt6 variant sysutils/libsysstat-qt6
EXPIRATION_DATE=2026-11-30

USES=		cmake compiler:c++17-lang lxqt:1 pkgconfig tar:xz qt:5
USE_QT=		qmake:build buildtools:build core
USE_LXQT=	buildtools
USE_LDCONFIG=	yes

post-extract:
	@${CP} ${FILESDIR}/config.h.in ${WRKSRC}

.include <bsd.port.mk>
