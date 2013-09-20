# Created by: brix@FreeBSD.org
# $FreeBSD$

PORTNAME=	Crypt-Eksblowfish
PORTVERSION=	0.009
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Perl module for the Eksblowfish block cipher

RUN_DEPENDS=	p5-Class-Mix>=0:${PORTSDIR}/devel/p5-Class-Mix \
		p5-parent>=0:${PORTSDIR}/devel/p5-parent

LICENSE_COMB=	dual
LICENSE=	ART10 GPLv1
USES=		perl5
USE_PERL5=	modbuild

MAN3=	Crypt::Eksblowfish.3 \
	Crypt::Eksblowfish::Bcrypt.3 \
	Crypt::Eksblowfish::Blowfish.3 \
	Crypt::Eksblowfish::Family.3 \
	Crypt::Eksblowfish::Subkeyed.3 \
	Crypt::Eksblowfish::Uklblowfish.3

NO_STAGE=	yes
.include <bsd.port.mk>
