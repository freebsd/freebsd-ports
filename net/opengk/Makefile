# New ports collection makefile for:	opengk
# Date created:		Mon Oct  8 12:49:00 BST 2001
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opengk
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/
DISTNAME=	opengk_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Equivalence's H323 GateKeeper for OpenH323 OhPhone and NetMeeting

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323-112:build

BROKEN=		Incomplete dependency list
DEPRECATED=	Latest version is from 2003-02-03. Use net/gatekeeper instead
EXPIRATION_DATE=	2006-07-01

WRKSRC=		${WRKDIR}/${PORTNAME}

NOCLEANDEPENDS=	yes

PLIST_FILES=	bin/opengk
USE_GMAKE=	yes
ALL_TARGET=	optnoshared
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../../devel/pwlib152/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323-112/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/opengk ${PREFIX}/bin

.include <bsd.port.mk>
