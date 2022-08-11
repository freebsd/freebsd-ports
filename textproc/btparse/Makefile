PORTNAME=	btparse
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AMBS/${PORTNAME}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	C library for parsing and processing BibTeX data files

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		perl5 libtool pathfix
USE_PERL5=	build

CONFLICTS_INSTALL=	p5-Text-BibTeX # bin/bibparse

.include <bsd.port.mk>
