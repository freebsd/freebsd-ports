# New ports collection makefile for:   dd_rescue
# Date created:        14 March 2005
# Whom:                MANTANI Nobutaka <nobutaka@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	dd_rescue
PORTVERSION=	1.11
CATEGORIES=	sysutils
MASTER_SITES=	http://www.garloff.de/kurt/linux/ddrescue/

MAINTAINER=	nobutaka@freebsd.org
COMMENT=	A dd tool suitable for rescuing data from a medium with errors

USE_GETOPT_LONG=yes
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	default

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib -lgnugetopt"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dd_rescue ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/README.dd_rescue ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
