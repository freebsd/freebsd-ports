# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-Folder-IMAP
PORTVERSION=	1.10.2
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Email::Folder Access to IMAP Folders

RUN_DEPENDS=	p5-Email-FolderType-Net>=0:mail/p5-Email-FolderType-Net \
		p5-Email-Folder>=0:mail/p5-Email-Folder \
		p5-Net-IMAP-Simple>=0.95:mail/p5-Net-IMAP-Simple \
		p5-URI-imap>=0:mail/p5-URI-imap
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure


.include <bsd.port.mk>
