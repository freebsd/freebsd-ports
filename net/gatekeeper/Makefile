# New ports collection makefile for:	gatekeeper
# Date created:		Wed Apr 15 15:41:00 GMT 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gatekeeper
PORTVERSION=	2.0.5
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= openh323gk
DISTNAME=	gk-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	roger@FreeBSD.org
COMMENT=	GnuGK is GPL Gate Keeper for OhPhone, GnomeMeeting, NetMeeting and H323

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/openh323gk

NOCLEANDEPENDS=	yes

USE_BISON=	yes
USE_GMAKE=	yes
ALL_TARGET=	optnoshared addpasswd
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../../devel/pwlib/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX} HAS_RADACCT=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/gnugk ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/addpasswd ${PREFIX}/bin

.include <bsd.port.mk>
