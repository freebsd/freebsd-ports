# New ports collection makefile for:	explosions
# Date created:				8 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	explosions
PORTVERSION=	0.2001.10.29
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/explosions/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^0.//}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	3D objects flying around resembling explosions with various effects

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

post-patch:
	@${PERL} -pi -e 's!CFLAGS=-Wall -O2!CFLAGS+=-Wall!; \
		s!sdl-config!${SDL_CONFIG}!' \
		${WRKSRC}/Makefile
	@${PERL} -pi -e 's!spark%d.png!${DATADIR}/spark%d.png!' \
		${WRKSRC}/explosions.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/explosions ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/spark?.png ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in BUGS.txt CHANGES.txt README.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
