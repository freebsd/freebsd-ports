PORTNAME=	libsysstat
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-qt6

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Library used to query system info and statistics ported to qt6
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++20-lang lxqt:2 pkgconfig tar:xz qt:6
USE_QT=		base:run tools:build
USE_LDCONFIG=	yes
USE_LXQT=	buildtools2

post-extract:
	@${CP} ${FILESDIR}/config.h.in ${WRKSRC}

.include <bsd.port.mk>
