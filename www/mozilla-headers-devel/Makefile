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

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Header files for mozilla communicator web-surfboard

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla-devel
.else
.if ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=	mozilla-devel-gtk2
.else
MOZILLA=	mozilla-devel
.endif
.endif

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/www/${MOZILLA}:configure

USE_X_PREFIX=	yes

LATEST_LINK=	mozilla-headers-devel
PLIST=		${WRKSRC}/pkg-plist
MAINDIR=	${.CURDIR}/../${MOZILLA}
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
		${SED} -e 's:^:include/mozilla-devel/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm include/mozilla-devel/:' >> ${PLIST}
	${ECHO_CMD} @dirrm include/mozilla-devel >> ${PLIST}

do-install:
	-${RM} -fr ${PREFIX}/include/mozilla-devel
	${MKDIR} ${PREFIX}/include/mozilla-devel
	${CHMOD} 755 ${PREFIX}/include/mozilla-devel
	cd ${WRKSRC}/dist/include && ${FIND} . | \
		cpio -pdm -L ${CPIOOWN} ${PREFIX}/include/mozilla-devel

.include <bsd.port.mk>
