# ports collection makefile for:	p5-Mail-GnuPG
# Date created:				Oct 16th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Mail-GnuPG
PORTVERSION=	0.06
CATEGORIES=	mail security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@dragon2.net
COMMENT=	Perl5 interface to process and/or create PGP email

BUILD_DEPENDS=	${SITE_PERL}/GnuPG/Interface.pm:${PORTSDIR}/security/p5-GnuPG-Interface \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::GnuPG.3

.include <bsd.port.mk>
