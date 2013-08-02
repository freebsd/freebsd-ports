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
USE_PERL5_BUILD=yes

MAN3=		btparse.3 bt_language.3 bt_input.3 bt_traversal.3 \
		bt_postprocess.3 bt_macros.3 bt_split_names.3 \
		bt_format_names.3 bt_misc.3

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
