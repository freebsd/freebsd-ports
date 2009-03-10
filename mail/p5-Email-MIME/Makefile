# New ports collection makefile for:	p5-Email-MIME
# Date created:				2004-08-29
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME
PORTVERSION=	1.863
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Easy MIME message parsing

RUN_DEPENDS=	p5-Email-Simple>=2.00.4:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Email-MIME-Encodings>=1.3:${PORTSDIR}/mail/p5-Email-MIME-Encodings \
		p5-Email-MIME-ContentType>=1.01.1:${PORTSDIR}/mail/p5-Email-MIME-ContentType \
		p5-MIME-Types>=1.13:${PORTSDIR}/mail/p5-MIME-Types
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::MIME.3 \
		Email::MIME::Header.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-MIME-Tools>=5.404:${PORTSDIR}/mail/p5-MIME-Tools
.else
RUN_DEPENDS+=	p5-Encode>=1.98.1:${PORTSDIR}/converters/p5-Encode
.endif

.include <bsd.port.post.mk>
