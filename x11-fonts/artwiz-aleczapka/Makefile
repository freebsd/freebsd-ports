# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	artwiz-aleczapka-en
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/artwizaleczapka/iso-8859-1/${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A set of (improved) artwiz fonts

NO_BUILD=	yes
USE_BZIP2=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

FONTS=		anorexia aqui cure cursor drift edges fkp gelly \
		glisp-bold glisp kates lime mints-mild mints-strong \
		nu smoothansi snap
FONTDIR=	${LOCALBASE}/lib/X11/fonts/${PORTNAME}/
FILES=		${FONTS:S,$,.pcf,} fonts.alias fonts.cache-1 fonts.dir

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
.for f in ${FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${FONTDIR}
.endfor

.include <bsd.port.post.mk>
