# New ports collection makefile for:	openh323
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openh323
PORTVERSION=	1.1b1
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/
DISTFILES=	openh323_1.1beta1.tar.gz \
		pwlib_min_1.1pl15.tar.gz

MAINTAINER=	roger@freebsd.org

WRKSRC=         ${WRKDIR}/${PORTNAME}

USE_NEWGCC=	yes
USE_BISON=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR=${WRKDIR}/pwlib \
		OPENH323DIR=${WRKDIR}/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}
MAN1=		ohphone.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sample/obj_${OPSYS}_${THE_MACHTYPE}_r/ohphone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sample/ohphone.1 ${PREFIX}/man/man1


.include <bsd.port.mk>
