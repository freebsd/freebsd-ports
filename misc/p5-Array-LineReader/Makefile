# Created by: chinsan
# $FreeBSD$

PORTNAME=	Array-LineReader
PORTVERSION=	1.01
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Access lines of a file via an array

BUILD_DEPENDS=	p5-IO>=0:${PORTSDIR}/devel/p5-IO
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Array::LineReader.3

PLIST_FILES=	%%SITE_PERL%%/Array/LineReader.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Array/LineReader/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Array/LineReader \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Array \
		%%SITE_PERL%%/Array

.include <bsd.port.mk>
