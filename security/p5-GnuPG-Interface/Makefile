# New ports collection makefile for:   p5-GnuPG-Interface
# Date created:                                2000-07-09
# Whom:                                        Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	GnuPG-Interface
PORTVERSION=	0.31
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	GnuPG gnupg-interface
PKGNAMEPREFIX=	p5-

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker
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
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
