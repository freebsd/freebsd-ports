# New ports collection makefile for:	mail/p5-Email-MIME-Creator
# Date created:				31 Ma 2006
# Whom:					Hashi, Hiroaki <hashiz@tomba.meridiani.jp>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME-Creator
PORTVERSION=	1.454
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hashiz@tomba.meridiani.jp
COMMENT=	Email::MIME constructor for starting anew

BUILD_DEPENDS=	p5-Email-MIME>=1.82:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-MIME-Modifier>=1.440:${PORTSDIR}/mail/p5-Email-MIME-Modifier \
		p5-Email-Simple>=1.92:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Email-Simple-Creator>=1.4:${PORTSDIR}/mail/p5-Email-Simple-Creator
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::MIME::Creator.3

.include <bsd.port.mk>
