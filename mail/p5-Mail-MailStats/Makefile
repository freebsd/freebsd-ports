# New ports collection makefile for:	MailStats
# Date created:				Wed Jan  3 15:09:46 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	MailStats
PORTVERSION=	0.02
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to detect newer messages in procmail-generated mailboxes

BUILD_DEPENDS=	${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::Stats::Record.3 Mail::Stats.3

.include <bsd.port.mk>
