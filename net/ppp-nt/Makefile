# New ports collection makefile for:	ppp + nat + time schedule
# Date created:		10 August 1998
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ppp
PORTVERSION=	2.2.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PORTS_JP} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sada
PKGNAMESUFFIX=	-nt

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=	nat-980920.patch.gz ppp-2.2.7-telehoudai.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	sada@FreeBSD.org

MANCOMPRESSED=	yes
MAN8=		ppp.8
WRKSRC=		${WRKDIR}/ppp
MAKE_ENV=	USE_SCHEDULE=YES

.SILENT:

do-configure:
.for i in Makefile
	${MV} -f ${WRKSRC}/${i} ${WRKSRC}/${i}.in
	${SED} -e "s;@PREFIX@;${PREFIX};g" ${WRKSRC}/${i}.in >${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
