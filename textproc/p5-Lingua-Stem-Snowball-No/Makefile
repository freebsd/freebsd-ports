# $FreeBSD$

PORTNAME=	Lingua-Stem-Snowball-No
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ASKSH
PKGNAMEPREFIX=	p5-
DISTNAME=	Snowball-Norwegian-${PORTVERSION}

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Stemmer for Norwegian

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	bin/stemmer-no.pl
NO_ARCH=	yes

.include <bsd.port.mk>
