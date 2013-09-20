# Created by: Dominic Marks <dominic.marks@btinternet.com>
# $FreeBSD$

PORTNAME=	artwiz-fonts
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://kobyla.info/soft/distfiles/ \
		LOCAL/garga/artwiz/
DISTNAME=	${PORTNAME}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A set of free fonts for X11 desktops

NO_BUILD=	yes
USE_BZIP2=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/fluxbox-${PORTNAME}

FONTS=		anorexia aqui cure cursor drift edges gelly glisp-bold \
		glisp lime mints-mild mints-strong nu snap
FONTDIR=	${LOCALBASE}/lib/X11/fonts/${PORTNAME}/
FILES=		${FONTS:S,$,.pcf.gz,} ${FILESDIR}/fonts.dir

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${FONTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${FONTDIR}

post-install:
	@${SED} 's|$${LOCALBASE}|${LOCALBASE}|g' \
		${PKGDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
