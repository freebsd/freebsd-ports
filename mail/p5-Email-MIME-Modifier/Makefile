# New ports collection makefile for:	mail/p5-Email-MIME-Modifier
# Date created:				27 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME-Modifier
PORTVERSION=	1.42
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Modify Email::MIME Objects Easily

BUILD_DEPENDS=	${SITE_PERL}/Email/MIME/Encodings.pm:${PORTSDIR}/mail/p5-Email-MIME-Encodings \
		${SITE_PERL}/Email/MIME.pm:${PORTSDIR}/mail/p5-Email-MIME \
		${SITE_PERL}/Email/MessageID.pm:${PORTSDIR}/mail/p5-Email-MessageID \
		${SITE_PERL}/Email/MIME/ContentType.pm:${PORTSDIR}/mail/p5-Email-MIME-ContentType \
		${SITE_PERL}/Email/Simple.pm:${PORTSDIR}/mail/p5-Email-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::MIME::Modifier.3

.include <bsd.port.mk>
