# New ports collection makefile for:	ohphone
# Date created:		Fri Aug 18 19:29:00 BST 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ohphone
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	roger@FreeBSD.org
COMMENT=	H323 Video Conferencing Program, compatible with NetMeeting

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/${PORTNAME}

NOCLEANDEPENDS=	yes

USE_BISON=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
ALL_TARGET=	optnoshared
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../../devel/pwlib/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}
MAN1=		ohphone.1
PLIST_FILES=	bin/ohphone

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/ohphone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ohphone.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
