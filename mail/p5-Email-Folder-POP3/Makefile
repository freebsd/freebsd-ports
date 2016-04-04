# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-Folder-POP3
PORTVERSION=	1.01.3
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Email::Folder access to POP3 folders

RUN_DEPENDS=	p5-URI>=1.35:net/p5-URI \
		p5-Email-FolderType-Net>=1.02:mail/p5-Email-FolderType-Net \
		p5-Email-Folder>=0.84:mail/p5-Email-Folder \
		p5-Net>=1.19:net/p5-Net
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
