# New ports collection makefile for:	ohphone
# Date created:		Fri Aug 18 19:29:00 BST 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ohphone
PORTVERSION=	1.1.7
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/
DISTNAME=	ohphone_1.1.7

MAINTAINER=	roger@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/${PORTNAME}

NOCLEANDEPENDS=	yes

USE_NEWGCC=	yes
USE_BISON=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}
MAN1=		ohphone.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/ohphone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ohphone.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
