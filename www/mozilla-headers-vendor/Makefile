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

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/www/mozilla-vendor:configure

USE_X_PREFIX=	yes

LATEST_LINK=	mozilla-headers-vendor
PLIST=		${WRKSRC}/pkg-plist
MAINDIR=	${.CURDIR}/../mozilla-vendor
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
	${RM} -f ${PLIST}
	${TOUCH} -f ${PLIST}
	cd ${WRKSRC}/dist/include && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:include/mozilla-vendor/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm include/mozilla-vendor/:' >> ${PLIST}
	${ECHO_CMD} @dirrm include/mozilla-vendor >> ${PLIST}

do-install:
	-${RM} -fr ${PREFIX}/include/mozilla-vendor
	${MKDIR} ${PREFIX}/include/mozilla-vendor
	${CHMOD} 755 ${PREFIX}/include/mozilla-vendor
	cd ${WRKSRC}/dist/include && ${FIND} . | \
		cpio -pdm -L ${CPIOOWN} ${PREFIX}/include/mozilla-vendor

.include <bsd.port.mk>
