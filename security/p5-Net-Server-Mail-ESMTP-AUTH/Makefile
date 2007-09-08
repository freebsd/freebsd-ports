# New ports collection makefile for:	p5-Net-Server-Mail-ESMTP-AUTH
# Date created:				20th July 2007
# Whom:					Zane C. Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Net-Server-Mail-ESMTP-AUTH
PORTVERSION=	0.1
CATEGORIES=	security mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Plain and login auth methods for Net::Server::Mail::ESMTP

BUILD_DEPENDS=	${SITE_PERL}/Net/Server/Mail/ESMTP.pm:${PORTSDIR}/mail/p5-Net-Server-Mail \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Server::Mail::ESMTP::AUTH.3

.include <bsd.port.mk>
