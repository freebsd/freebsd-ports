# New ports collection makefile for:	mozilla-headers
# Date created:				1 February 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mozilla-headers
PORTVERSION=	${MAKE} -V PORTVERSION -f ${MAINDIR}/${MKFILE}
PORTREVISION=	${MAKE} -V PORTREVISION -f ${MAINDIR}/${MKFILE}
PORTEPOCH=	${MAKE} -V PORTEPOCH -f ${MAINDIR}/${MKFILE}
CATEGORIES=	www
DISTFILES=

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/www/mozilla:configure

USE_X_PREFIX=	yes

PLIST=		${WRKSRC}/pkg-plist
MAINDIR=	${.CURDIR}/../mozilla
MKFILE!=	/usr/bin/basename ${MAKEFILE}
PORTVERSION!=	${PORTVERSION}
PORTREVISION!=	${PORTREVISION}
PORTEPOCH!=	${PORTEPOCH}
WRKSRC=		${WRKDIRPREFIX}${MAINDIR}/work/mozilla
USE_GMAKE=	yes
ALL_TARGET=	export

.if defined(INCOWN) || defined(INCGRP)
CPIOOWN=	-R ${INCOWN}:${INCGRP}
.endif

pre-install:
	${TOUCH} -f ${PLIST}
	cd ${WRKSRC}/dist/include && ${FIND} -s * -type f -o -type l | \
		${SED} -e ':^:include/mozilla/:' >> ${PLIST} \
		&& ${FIND} -d * -type f | \
		${SED} -e 's:^:@dirrm include/mozilla/:' >> ${PLIST}
	${ECHO_CMD} @dirrm include/mozilla >> ${PLIST}

do-install:
	-${RM} -fr ${PREFIX}/include/mozilla
	${MKDIR} ${PREFIX}/include/mozilla
	${CHMOD} 755 ${PREFIX}/include/mozilla
	cd ${WRKSRC}/dist/include && ${FIND} . | \
		cpio -pdm -L ${CPIOOWN} ${PREFIX}/include/mozilla

.include <bsd.port.mk>
