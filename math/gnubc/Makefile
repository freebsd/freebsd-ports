# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bc
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gnu

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	The GNU bc/dc calculator

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

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
