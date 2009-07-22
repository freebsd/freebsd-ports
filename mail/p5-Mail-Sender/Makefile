# New ports collection makefile for:	p5-Mail-Sender
# Date created:				July 27th 2000
# Whom:	      				Ben Smithurst <ben@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-Sender
PORTVERSION=	0.8.16
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Module for sending mails with attachments through an SMTP server

PERL_CONFIGURE=	yes

MAN3=		Mail::Sender.3

post-patch:
.if defined(BATCH)
	@${PERL} -pi -e 's/res = <STDIN>;/res = "N";/' ${WRKSRC}/Config.PL
.endif

.include <bsd.port.mk>
