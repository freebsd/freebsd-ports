# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Lingua-EN-MatchNames
PORTVERSION=	1.36
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Smart matching for human names

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Lingua-EN-NameParse>=0:textproc/p5-Lingua-EN-NameParse \
		p5-Lingua-EN-Nickname>=0:textproc/p5-Lingua-EN-Nickname \
		p5-String-Approx>=0:devel/p5-String-Approx \
		p5-Text-Metaphone>=0:textproc/p5-Text-Metaphone
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Text-Soundex>=0:textproc/p5-Text-Soundex
RUN_DEPENDS+=	p5-Text-Soundex>=0:textproc/p5-Text-Soundex
.endif

.include <bsd.port.post.mk>
