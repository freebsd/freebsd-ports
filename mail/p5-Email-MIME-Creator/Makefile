# New ports collection makefile for:	mail/p5-Email-MIME-Creator
# Date created:				31 Ma 2006
# Whom:					Hashi, Hiroaki <hashiz@tomba.meridiani.jp>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME-Creator
PORTVERSION=	1.453
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	hashiz@tomba.meridiani.jp
COMMENT=	Email::MIME constructor for starting anew

BUILD_DEPENDS=	${SITE_PERL}/Email/MIME/Modifier.pm:${PORTSDIR}/mail/p5-Email-MIME-Modifier \
		${SITE_PERL}/Email/MIME.pm:${PORTSDIR}/mail/p5-Email-MIME \
		${SITE_PERL}/Email/Simple/Creator.pm:${PORTSDIR}/mail/p5-Email-Simple-Creator
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::MIME::Creator.3

.include <bsd.port.mk>
