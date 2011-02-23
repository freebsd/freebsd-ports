# New ports collection makefile for:	p5-Array-FileReader
# Date created:				2011/02/20
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Array-FileReader
PORTVERSION=	0.03
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Lazily tie files to arrays for reading

BUILD_DEPENDS=	p5-IO>=0:${PORTSDIR}/devel/p5-IO
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Array::FileReader.3

PLIST_FILES=	%%SITE_PERL%%/Array/FileReader.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Array/FileReader/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Array/FileReader \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Array \
		%%SITE_PERL%%/Array

.include <bsd.port.mk>
