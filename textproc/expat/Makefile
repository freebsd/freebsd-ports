# New ports collection makefile for:	expat
# Date created:		Thu Aug 26 14:38:07 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/

MAINTAINER=	knu@FreeBSD.org

SHLIB_MAJOR=	1

MAKEFILES=	Makefile.lib Makefile.prog
MAKE_ARGS=	SHLIB_MAJOR="${SHLIB_MAJOR}" \
		NOPROFILE=true
INSTALLS_SHLIB=	yes
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

do-build:
.for f in ${MAKEFILES}
	${CP} ${FILESDIR}/${f} ${WRKSRC}/
.endfor
	${MV} ${WRKSRC}/xmlwf/* ${WRKSRC}/
	${RMDIR} ${WRKSRC}/xmlwf
.for f in ${MAKEFILES}
	@(cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${f} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
.for f in ${MAKEFILES}
	@(cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${f} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor

.include <bsd.port.mk>
