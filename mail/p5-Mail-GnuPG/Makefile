# ports collection makefile for:	p5-Mail-GnuPG
# Date created:				Oct 16th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Mail-GnuPG
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	mail security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@dragon2.net
COMMENT=	Perl5 interface to process and/or create PGP email

BUILD_DEPENDS=	${SITE_PERL}/GnuPG/Interface.pm:${PORTSDIR}/security/p5-GnuPG-Interface \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::GnuPG.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
