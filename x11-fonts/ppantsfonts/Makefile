# New ports collection makefile for:	ppants-fonts
# Date created:				06/07/2003
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	ppantsfonts
PORTVERSION=	0.7
CATEGORIES=	x11-fonts
MASTER_SITES=	http://cus.org.uk/~dom/distfiles/ppants-fonts/
DISTNAME=	${PORTNAME}-default-${PORTVERSION}

MAINTAINER=	dominic.marks@btinternet.com
COMMENT=	A set of small angular fonts

NO_BUILD=	yes
USE_X_PREFIX=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

FONTS=	moosefont terminalpants
FONTDIR=	${X11BASE}/lib/X11/fonts/${PORTNAME}/
FILES=	${FONTS:S,$,.pcf.gz,} ${FILESDIR}/fonts.dir
WRKSRC=	${WRKDIR}/ppants

.include <bsd.port.pre.mk>

do-install:
.for FONT in ${FONTS:S,$,.pcf,}
	cd ${WRKSRC} && ${GZIP_CMD} ${FONT}
.endfor
	@${MKDIR} ${FONTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${FONTDIR}

post-install:
	@${SED} 's,$${X11BASE},${X11BASE},g' \
		${PKGDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
