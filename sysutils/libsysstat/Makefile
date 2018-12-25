# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libsysstat
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Library used to query system info and statistics

LICENSE=	LGPL21

USES=	cmake compiler:c++11-lang lxqt pkgconfig tar:xz qt:5
USE_QT=	qmake_build buildtools_build core
USE_LXQT=	buildtools

post-extract:
	@${CP} ${FILESDIR}/config.h.in ${WRKSRC};

.include <bsd.port.mk>
