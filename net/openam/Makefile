# New ports collection makefile for:	openam
# Date created:		Tue May  2 15:43:02 BST 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openam
PORTVERSION=	1.1.4
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/
DISTNAME=	openam_1.1.4

MAINTAINER=	roger@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/${PORTNAME}

NOCLEANDEPENDS=	yes

USE_NEWGCC=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/openam ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/openh323/openam
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${PREFIX}/share/doc/openh323/openam
	${INSTALL_DATA} ${WRKSRC}/sample_message.wav ${PREFIX}/share/doc/openh323/openam
	${INSTALL_DATA} ${WRKSRC}/sample_message_g7231.wav ${PREFIX}/share/doc/openh323/openam

.include <bsd.port.mk>
