# New ports collection makefile for:	p5-Amazon-SQS-Simple
# Date created:		2007-10-31
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Amazon-SQS-Simple
PORTVERSION=	1.04
CATEGORIES=	net perl5
MASTER_SITES=	CPAN/../../authors/id/S/SW/SWHITAKER
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	OO API for accessing the Amazon Simple Queue Service

BUILD_DEPENDS=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Digest/HMAC_SHA1.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Amazon::SQS::Simple::Message.3 \
		Amazon::SQS::Simple::Queue.3 \
		Amazon::SQS::Simple::Base.3 \
		Amazon::SQS::Simple::SendResponse.3 \
		Amazon::SQS::Simple.3

SUB_FILES=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
