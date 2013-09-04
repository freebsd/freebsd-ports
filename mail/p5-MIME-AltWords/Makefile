# New ports collection makefile for:	p5-MIME-AltWords
# Date created:		Jun 06 2011
# Whom:			Dmitry Liakh <dliakh@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	MIME-AltWords
PORTVERSION=	0.12
CATEGORIES=	mail
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dliakh@ukr.net
COMMENT=	Perl module for encoding and decoding MIME words

USES=		perl5
USE_PERL5=	configure

MAN3=		MIME::AltWords.3 \
		MIME::AltWords0.3

post-patch:
	@${REINPLACE_CMD} -e '/NAME/ s|MIME-AltWords|MIME::AltWords|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
