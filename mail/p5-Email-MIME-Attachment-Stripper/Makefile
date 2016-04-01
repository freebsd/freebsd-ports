# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-MIME-Attachment-Stripper
PORTVERSION=	1.31.6
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C|\.([0-9])$|\1|}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Strip the attachments from a mail

RUN_DEPENDS=	p5-Email-MIME>=1.861:mail/p5-Email-MIME \
		p5-Email-MIME-ContentType>=1.0:mail/p5-Email-MIME-ContentType
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
