# New ports collection makefile for:	p5-Email-LocalDelivery
# Date created:				August 31 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-LocalDelivery
PORTVERSION=	0.21.7
DISTVERSION=	${PORTVERSION:C/\.(.)$/\1/}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Deliver a piece of email - simply

RUN_DEPENDS=	${SITE_PERL}/Email/Simple.pm:${PORTSDIR}/mail/p5-Email-Simple \
		${SITE_PERL}/Email/FolderType.pm:${PORTSDIR}/mail/p5-Email-FolderType \
		${SITE_PERL}/File/Path/Expand.pm:${PORTSDIR}/devel/p5-File-Path-Expand
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::LocalDelivery.3

.include <bsd.port.mk>
