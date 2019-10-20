# Created by: will
# $FreeBSD$

PORTNAME=	Mail-Box
PORTVERSION=	3.008
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module implementing a modern mail folder management

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Devel-GlobalDestruction>=0.09:devel/p5-Devel-GlobalDestruction \
		p5-File-Remove>=0.20:devel/p5-File-Remove \
		p5-IO-stringy>=0:devel/p5-IO-stringy \
		p5-Mail-Message>=3.008:mail/p5-Mail-Message \
		p5-Mail-Transport>=3.003:mail/p5-Mail-Transport \
		p5-Object-Realize-Later>=0.19:devel/p5-Object-Realize-Later \
		p5-TimeDate>=0:devel/p5-TimeDate

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
