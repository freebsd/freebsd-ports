# New ports collection makefile for:	openh323
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openh323
PORTVERSION=	1.12.2
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.gnomemeeting.org/downloads/0.98.0/sources/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A H323 Video Conferencing library

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/pwlib:build
LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500000
# Check for telephony.h in the two places the source is hard coded to check
# /usr/include/sys and /usr/local/include/sys
# If it is not present, extract it from the comms/ixj port
.if !exists(/usr/include/sys/telephony.h)
.if !exists(/usr/local/include/sys/telephony.h)
PATCH_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/comms/ixj:patch
.endif
.endif
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/simph323
USE_BISON=	yes

USE_GMAKE=	yes
USE_OPENLDAP=	yes
USE_AUTOCONF_VER=	259
GNU_CONFIGURE=	yes
PWLIBDIR!=	cd ${PORTSDIR}/devel/pwlib && make -V WRKSRC
CONFIGURE_ENV=	PWLIBDIR=${PWLIBDIR} OPENH323DIR=${WRKSRC}
ALL_TARGET=	optnoshared
MAKE_ENV=	PWLIBDIR=${PWLIBDIR} OPENH323DIR=${WRKSRC}
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

post-patch:
.if ${OSVERSION} < 500000
.if !exists(/usr/include/sys/telephony.h)
.if !exists(/usr/local/include/sys/telephony.h)
	# Copy ixj driver include files into OpenH323 include directory
	${MKDIR} ${WRKDIR}/openh323/include/sys
	${CP} ${WRKDIRPREFIX}${.CURDIR}/../../comms/ixj/work/ixj_freebsd/telephony.h ${WRKDIR}/openh323/include/sys
	${CP} ${WRKDIRPREFIX}${.CURDIR}/../../comms/ixj/work/ixj_freebsd/ixjuser.h ${WRKDIR}/openh323/include/sys
.endif
.endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/samples/simple/obj_${OPSYS}_${THE_MACHTYPE}_r/simph323 ${PREFIX}/bin

.include <bsd.port.post.mk>
