# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Email-Folder
PORTVERSION=	0.85.5
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Read all the messages from a folder as Email::Simple objects

RUN_DEPENDS=	p5-Email-Simple>0:mail/p5-Email-Simple \
		p5-Email-FolderType>=0.6:mail/p5-Email-FolderType
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
