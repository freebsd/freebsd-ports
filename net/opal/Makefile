# New ports collection makefile for:	openh323
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openh323
PORTVERSION=	1.7.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/
DISTFILES=	openh323_1.7.4.tar.gz \
		pwlib_1.2.5.tar.gz

MAINTAINER=	roger@freebsd.org

# Check for telephony.h in the two places the source is hard coded to check
# /usr/include/sys and /usr/local/include/sys
# If it is not present, extract it from the comms/ixj port
.if !exists(/usr/include/sys/telephony.h)
.if !exists(/usr/local/include/sys/telephony.h)
BUILD_DEPENDS=  ${NONEXISTENT}:${PORTSDIR}/comms/ixj:patch
.endif
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_NEWGCC=	yes
USE_BISON=	yes

USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR=${WRKDIR}/pwlib \
		OPENH323DIR=${WRKDIR}/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

post-patch:
.if !exists(/usr/include/sys/telephony.h)
.if !exists(/usr/local/include/sys/telephony.h)
	# Copy ixj driver include files into OpenH323 include directory
	${MKDIR} ${WRKDIR}/openh323/include/sys
	${CP} ${WRKDIRPREFIX}${.CURDIR}/../../comms/ixj/work/ixj_freebsd/telephony.h ${WRKDIR}/openh323/include/sys
	${CP} ${WRKDIRPREFIX}${.CURDIR}/../../comms/ixj/work/ixj_freebsd/ixjuser.h ${WRKDIR}/openh323/include/sys
.endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/samples/simple/obj_${OPSYS}_${THE_MACHTYPE}_r/simph323 ${PREFIX}/bin

.include <bsd.port.mk>
