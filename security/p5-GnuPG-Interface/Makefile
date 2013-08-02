# Created by: trevor
# $FreeBSD$

PORTNAME=	GnuPG-Interface
PORTVERSION=	0.46
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for interfacing with GnuPG

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg \
		p5-Any-Moose>=0.04:${PORTSDIR}/devel/p5-Any-Moose
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	GnuPG::Fingerprint.3 \
	GnuPG::Handles.3 \
	GnuPG::Interface.3 \
	GnuPG::Key.3 \
	GnuPG::Options.3 \
	GnuPG::PrimaryKey.3 \
	GnuPG::PublicKey.3 \
	GnuPG::Revoker.3 \
	GnuPG::SecretKey.3 \
	GnuPG::Signature.3 \
	GnuPG::SubKey.3 \
	GnuPG::UserAttribute.3 \
	GnuPG::UserId.3

.include <bsd.port.mk>
