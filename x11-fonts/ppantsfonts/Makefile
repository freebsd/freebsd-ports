# Created by: Dominic Marks <dominic.marks@btinternet.com>
# $FreeBSD$

PORTNAME=	ppantsfonts
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://cus.org.uk/~dom/distfiles/ppants-fonts/
DISTNAME=	${PORTNAME}-default-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of small angular fonts

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

BROKEN=		checksum mismatch

FONTS=	moosefont terminalpants
FONTDIR=	${LOCALBASE}/lib/X11/fonts/${PORTNAME}/
FILES=	${FONTS:S,$,.pcf.gz,} ${FILESDIR}/fonts.dir
WRKSRC=	${WRKDIR}/ppants

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
.for FONT in ${FONTS:S,$,.pcf,}
	cd ${WRKSRC} && ${GZIP_CMD} ${FONT}
.endfor
	@${MKDIR} ${FONTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${FONTDIR}

post-install:
	@${SED} 's,$${LOCALBASE},${LOCALBASE},g' \
		${PKGDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
