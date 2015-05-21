# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bc
PORTVERSION=	1.06
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	GNU
PKGNAMEPREFIX=	gnu

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	GNU bc/dc calculator

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libedit
INFO=		bc \
		dc
PLIST_FILES=	bin/bc \
		bin/dc \
		man/man1/bc.1.gz \
		man/man1/dc.1.gz
PORTEXAMPLES=	ckbook.b \
		pi.b \
		primes.b \
		twins.b

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
