# New ports collection makefile for:	p5-Mail-Procmail
# Date Created:				13 Oct 2003
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	Mail-Procmail
PORTVERSION=	1.08
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module provides procmail-like tools

BUILD_DEPENDS=	${SITE_PERL}/LockFile/Lock.pm:${PORTSDIR}/devel/p5-LockFile-Simple \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		Mail::Procmail.3

.include <bsd.port.mk>
