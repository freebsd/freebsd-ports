# New ports collection makefile for:	cphone
# Date created:		Thu May 24 15:50:00 BST 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cphone
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	H323 Video Conferencing Program which uses QT

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323:build \
		qmake:${PORTSDIR}/devel/qmake

NOCLEANDEPENDS=	yes

PLIST_FILES=	bin/cphone
USE_BZIP2=	yes
USE_BISON=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
ALL_TARGET=	optnoshared
MAKE_ENV=	QTDIR=${X11BASE} \
		PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../../devel/pwlib/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/cphone ${PREFIX}/bin

.include <bsd.port.post.mk>
