# New ports collection makefile for:	openam
# Date created:		Tue May  2 15:43:02 BST 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openam
PORTVERSION=	0.2.alpha1
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/

DISTNAME=	openam_0.2alpha1

MAINTAINER=	roger@freebsd.org

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/openam

NOCLEANDEPENDS=	yes

USE_NEWGCC=	yes
USE_BISON=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/openam ${PREFIX}/bin

.include <bsd.port.mk>
