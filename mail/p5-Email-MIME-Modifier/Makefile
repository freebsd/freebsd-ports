# New ports collection makefile for:	mail/p5-Email-MIME-Modifier
# Date created:				27 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME-Modifier
PORTVERSION=	1.444
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Modify Email::MIME Objects Easily

BUILD_DEPENDS=	p5-Email-MIME-Encodings>=1.313:${PORTSDIR}/mail/p5-Email-MIME-Encodings \
		p5-Email-MIME>=1.82:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-MessageID>=1.2:${PORTSDIR}/mail/p5-Email-MessageID \
		p5-Email-MIME-ContentType>=1.0:${PORTSDIR}/mail/p5-Email-MIME-ContentType \
		p5-Email-Simple>=1.92:${PORTSDIR}/mail/p5-Email-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::MIME::Modifier.3

.include <bsd.port.mk>
