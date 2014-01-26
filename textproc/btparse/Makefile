# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	btparse
PORTVERSION=	0.35
CATEGORIES=	textproc
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AMBS/${PORTNAME}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	C library for parsing and processing BibTeX data files

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		perl5
USE_PERL5=	build

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
