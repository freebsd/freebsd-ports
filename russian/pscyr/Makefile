# New ports collection makefile for:	PSCyr
# Date created:				29 Jun 2001
# Whom:					kapr@crosswinds.net
#
# $FreeBSD$
#

PORTNAME=	PSCyr
PATCH_LEVEL=	2
PORTVERSION=	0.4c${PATCH_LEVEL}
PORTREVISION=	2
CATEGORIES=	russian print
MASTER_SITES=	ftp://scon155.phys.msu.su/pub/russian/psfonts/ \
		ftp://ftp.vsu.ru/pub/tex/font-packs/pscyr/
DISTFILES=	${PORTNAME}-${PORTVERSION:S/${PATCH_LEVEL}$/-patch&/}-tex.tar.gz \
		${PORTNAME}-${PORTVERSION:S/${PATCH_LEVEL}$/-patch&/}-type1.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cyrillic PostScript Type1 fonts for use with TeX

RUN_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
# no other TeX is sufficient

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
MAKE_ENV=	TEXMFDIR=${LOCALBASE}/share/texmf
PLIST_SUB=	UPDMAP_SYS=${UPDMAP_SYS} \
		MKTEXLSR=${MKTEXLSR}

UPDMAP_SYS?=	${LOCALBASE}/bin/updmap-sys
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

do-install:
	(cd ${WRKDIR}; ${SETENV} ${MAKE_ENV} ${SH} install.sh)

post-install:
	${MKTEXLSR}
	${UPDMAP_SYS} --quiet --nomkmap --enable Map=pscyr.map
	${UPDMAP_SYS} --quiet --enable Map=pscyr2.map

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
