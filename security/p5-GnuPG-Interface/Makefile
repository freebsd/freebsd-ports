# New ports collection makefile for:   p5-GnuPG-Interface
# Date created:                                2000-07-09
# Whom:                                        Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	GnuPG-Interface
PORTVERSION=	0.34
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnupg-interface
PKGNAMEPREFIX=	p5-

MAINTAINER=	eol1@yahoo.com
COMMENT=	Perl module for interfacing with GnuPG

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker \
		${RUN_DEPENDS}
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

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

.include <bsd.port.pre.mk>

# p5-GnuPG-Interface -> p5-Class-MethodMaker
.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
