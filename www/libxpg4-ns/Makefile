# New ports collection makefile for:	libxpg4-ns
# Date created:		27 February 1999
# Whom:			sada
#
# $FreeBSD$
#

PORTNAME=	libxpg4
PORTVERSION=	3.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sada
PKGNAMESUFFIX=	-ns
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	sada@FreeBSD.ORG

PORTOBJFORMAT=	aout
NO_BUILD=	yes

LIBDIR=		${PREFIX}/lib/aout

pre-install:
	${MKDIR} ${LIBDIR}
do-install:
.for file in libxpg4-ns.a libxpg4-ns.so.2.0 libxpg4-ns_p.a
	${INSTALL_DATA} ${WRKSRC}/${file} ${LIBDIR}
.endfor
post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${LIBDIR}

.include <bsd.port.mk>
