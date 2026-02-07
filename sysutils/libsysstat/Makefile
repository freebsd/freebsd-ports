PORTNAME=	libsysstat
PORTVERSION=	0.4.6
CATEGORIES=	sysutils
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Library used to query system info and statistics
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang lxqt:1 pkgconfig tar:xz qt:5
USE_QT=		qmake:build buildtools:build core
USE_LXQT=	buildtools
USE_LDCONFIG=	yes

post-extract:
	@${CP} ${FILESDIR}/config.h.in ${WRKSRC}

.include <bsd.port.mk>
