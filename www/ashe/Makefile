# New ports collection makefile for:	ashe
# Date created:		16 October 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	ashe
PORTVERSION=	1.3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cs.rpi.edu/pub/puninj/ASHE/ASHE-1.3/%SUBDIR%/
MASTER_SITE_SUBDIR=	src libcci libhtmlw-2.7
DISTFILES=	xhtml-1.3.tar.Z cci.tar.Z libhtmlw.tar.Z

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes
CONFIGURE_WRKSRC=	${WRKDIR}/src
INSTALL_WRKSRC=		${WRKDIR}/src

USE_MOTIF=	yes
USE_IMAKE=	yes
MAN1=		xhtml.1

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/XHTML.ad
	@${PERL} -pi -e "s/malloc.h/stdlib.h/g" \
		${WRKSRC}/libhtmlw-2.7b3/HTML-PSformat.c

do-build:
.for dir in libhtmlw-2.7b3 libcci src
	@(cd ${WRKDIR}/${dir}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

.include <bsd.port.mk>
