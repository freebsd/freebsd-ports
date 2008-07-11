# New ports collection makefile for:	p5-Email-MIME-Attachment-Stripper
# Date created:				2004-08-30
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME-Attachment-Stripper
PORTVERSION=	1.31.5
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C|\.([0-9])$|\1|}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Strip the attachments from a mail

RUN_DEPENDS=	p5-Email-MIME>=1.861:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-MIME-ContentType>=1.0:${PORTSDIR}/mail/p5-Email-MIME-ContentType \
		p5-Email-MIME-Modifier>=1.41:${PORTSDIR}/mail/p5-Email-MIME-Modifier
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::MIME::Attachment::Stripper.3

.include <bsd.port.mk>
