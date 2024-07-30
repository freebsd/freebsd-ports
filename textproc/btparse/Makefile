PORTNAME=	btparse
PORTVERSION=	0.35
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AMBS/btparse

MAINTAINER=	perl@FreeBSD.org
COMMENT=	C library for parsing and processing BibTeX data files
WWW=		https://www.gerg.ca/software/btOOL/

DEPRECATED=	btparse has not updated for 19 years while p5-Text-BibTeX is up-to-date. Use textproc/p5-Text-BibTeX instead
EXPIRATION_DATE=2024-08-31

USES=		libtool pathfix perl5
USE_PERL5=	build

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	p5-Text-BibTeX # bin/bibparse

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libbtparse.so

.include <bsd.port.mk>
