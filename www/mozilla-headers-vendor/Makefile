# New ports collection makefile for:	mozilla-headers
# Date created:				1 February 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mozilla-headers
PORTVERSION=	${MAKE} -V PORTVERSION -f ${MAINDIR}/${MAKEFILE}
PORTREVISION=	${MAKE} -V PORTREVISION -f ${MAINDIR}/${MAKEFILE}
PORTEPOCH=	${MAKE} -V PORTEPOCH -f ${MAINDIR}/${MAKEFILE}
CATEGORIES=	www
DISTFILES=

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/www/mozilla:configure

USE_X_PREFIX=	yes

MAINDIR=	${.CURDIR}/../mozilla
PORTVERSION!=	${PORTVERSION}
PORTREVISION!=	${PORTREVISION}
PORTEPOCH!=	${PORTEPOCH}
RUN_DEPENDS!=	${RUN_DEPENDS}
LIB_DEPENDS!=	${LIB_DEPENDS}
WRKSRC=		${WRKDIRPREFIX}${MAINDIR}/work/mozilla
USE_GMAKE=	yes
ALL_TARGET=	export

do-install:
	${MKDIR} ${PREFIX}/include/mozilla
	${CHMOD} 755 ${PREFIX}/include/mozilla
	cd ${WRKSRC}/dist/include && ${TAR} -chf - . | \
		${TAR} --unlink -xf - -C ${PREFIX}/include/mozilla

.include <bsd.port.mk>
