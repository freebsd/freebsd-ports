# New ports collection makefile for:   p5-GnuPG-Interface
# Date created:                                2000-07-09
# Whom:                                        Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	GnuPG-Interface
PORTVERSION=    0.09
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GnuPG
PKGNAMEPREFIX=	p5-

MAINTAINER=	trevor@jpj.net

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker

USE_PERL5=	yes

MAN3=	GnuPG::Handles.3 \
	GnuPG::SecretKey.3 \
	GnuPG::Interface.3 \
	GnuPG::Signature.3 \
	GnuPG::SubKey.3 \
	GnuPG::Fingerprint.3 \
	GnuPG::PublicKey.3 \
	GnuPG::Key.3 \
	GnuPG::UserId.3 \
	GnuPG::Options.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
