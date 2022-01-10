# Created by: David Bremner <bremner@unb.ca>

PORTNAME=	Text-BibTeX
PORTVERSION=	0.88
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate BibTeX files from perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-AutoConf>=0.16:devel/p5-Config-AutoConf \
		p5-ExtUtils-LibBuilder>=0.02:devel/p5-ExtUtils-LibBuilder
TEST_DEPENDS=	p5-Capture-Tiny>=0.06:devel/p5-Capture-Tiny

USES=		perl5
USE_CSTD=	c99
USE_PERL5=	modbuild

CFLAGS_amd64=	-fPIC
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	btparse # bin/bibparse

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libbtparse.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Text/BibTeX/BibTeX.so

.include <bsd.port.mk>
