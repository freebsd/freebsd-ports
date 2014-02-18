# Created by: shige
# $FreeBSD$

PORTNAME=	mkcatalog
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A maintenance utility for sgml catalog files

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	sbin/mkcatalog
SCRIPTS_ENV=	CONFIGURE_TARGETS=${CONFIGURE_TARGETS}

SRC=			${.CURDIR}/src
CONFIGURE_TARGETS=	mkcatalog

do-fetch:
	@${DO_NADA}

pre-configure:
.for f in ${CONFIGURE_TARGETS}
	${CP} ${SRC}/${f}.in ${WRKDIR}
.endfor

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/mkcatalog \
		${STAGEDIR}${PREFIX}/sbin/mkcatalog

.include <bsd.port.mk>
