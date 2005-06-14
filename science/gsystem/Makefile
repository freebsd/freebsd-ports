# New ports collection makefile for:	G System
# Date created:				16 December 2004
# Whom:					Raphael Langerhorst <raphael-langerhorst@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gsystem
PORTVERSION=	0.5.1
CATEGORIES=	science devel games
MASTER_SITES=	ftp://ftp.g-system.at/pub/gsystem/releases/development/${PORTVERSION}/
DISTNAME=	G-System-${PORTVERSION}

MAINTAINER=	raphael-langerhorst@gmx.at
COMMENT=	A multi-user virtual reality evolution and life simulation framework

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_BZIP2=	yes

USE_KDELIBS_VER=	3

INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes

QTDIR=		${X11BASE}
QMAKESPEC=	freebsd-g++

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"does not compile with gcc 2.95"
.endif

do-configure:
	cd ${WRKSRC}; \
	export QTDIR=${QTDIR}; \
	export QMAKESPEC=${QMAKESPEC}; \
	qmake;

do-build:
	cd ${WRKSRC}; \
	export QTDIR=${QTDIR}; \
	export QMAKESPEC=${QMAKESPEC}; \
	./scripts/compile;

do-install:
	cd ${WRKSRC}; \
	export G_PREFIX=${PREFIX}; \
	export G_NO_INST_DOCS=yes; \
	./scripts/makeinstall;

post-install:
	@${CAT} ${PKGMESSAGE};

.include <bsd.port.post.mk>
