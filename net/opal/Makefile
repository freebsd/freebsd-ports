# New ports collection makefile for:	openh323
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openh323
PORTVERSION=	1.1pl1
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/
DISTFILES=	openh323_1.1pl1.tar.gz \
		pwlib_min_1.1pl19.tar.gz

MAINTAINER=	roger@freebsd.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_NEWGCC=	yes
USE_BISON=	yes

# If the user compiles with make -DNO_XWINDOWS do not include X support
.if !defined(NO_XWINDOWS)
USE_XLIB=	yes
.endif

USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR=${WRKDIR}/pwlib \
		OPENH323DIR=${WRKDIR}/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}
.if defined(NO_XWINDOWS)
MAKE_ARGS+=	NO_XWINDOWS=1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/samples/simple/obj_${OPSYS}_${THE_MACHTYPE}_r/simph323 ${PREFIX}/bin

.include <bsd.port.mk>
