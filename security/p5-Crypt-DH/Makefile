# Created by: jesper
# $FreeBSD$

PORTNAME=	Crypt-DH
PORTVERSION=	0.07
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to a Diffie-Hellman key exchange system

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

MAN3=		Crypt::DH.3
PLIST_FILES=	%%SITE_PERL%%/Crypt/DH.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Crypt/DH/.packlist
PLIST_DIRSTRY=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Crypt/DH \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Crypt \
		%%SITE_PERL%%/Crypt

.include <bsd.port.mk>
