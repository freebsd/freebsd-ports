# Created by: David Bremner <bremner@unb.ca>
# $FreeBSD$

PORTNAME=	Text-BibTeX
PORTVERSION=	0.77
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate BibTeX files from perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-AutoConf>=0.16:devel/p5-Config-AutoConf \
		p5-ExtUtils-LibBuilder>=0.02:devel/p5-ExtUtils-LibBuilder
TEST_DEPENDS=	p5-Capture-Tiny>=0.06:devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	modbuild
USE_LDCONFIG=	yes

STRIP_FILES=	bin/dumpnames bin/biblex bin/bibparse \
		${SITE_ARCH_REL}/auto/Text/BibTeX/BibTeX.so \
		lib/libbtparse.so

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502300
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=0.42:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=0.42:lang/p5-Scalar-List-Utils
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-install:
	${STRIP_CMD} ${STRIP_FILES:S|^|${STAGEDIR}${PREFIX}/|}

.include <bsd.port.post.mk>
