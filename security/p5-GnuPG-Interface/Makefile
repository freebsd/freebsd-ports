# New ports collection makefile for:   p5-GnuPG-Interface
# Date created:                                2000-07-09
# Whom:                                        Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	GnuPG-Interface
PORTVERSION=	0.33
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	GnuPG gnupg-interface
PKGNAMEPREFIX=	p5-

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Perl module for interfacing with GnuPG

BUILD_DEPENDS=	${SITE_PERL}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	GnuPG::Fingerprint.3 \
	GnuPG::Handles.3 \
	GnuPG::Interface.3 \
	GnuPG::Key.3 \
	GnuPG::Options.3 \
	GnuPG::PrimaryKey.3 \
	GnuPG::PublicKey.3 \
	GnuPG::SecretKey.3 \
	GnuPG::Signature.3 \
	GnuPG::SubKey.3 \
	GnuPG::UserId.3

.include <bsd.port.mk>
