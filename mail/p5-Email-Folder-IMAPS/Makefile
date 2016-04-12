# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-Folder-IMAPS
PORTVERSION=	1.10.2
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Email::Folder access to IMAP over SSL folders

RUN_DEPENDS=	p5-Email-FolderType-Net>=0:mail/p5-Email-FolderType-Net \
		p5-Email-Folder-IMAP>=1.10.2:mail/p5-Email-Folder-IMAP \
		p5-Net-IMAP-Simple-SSL>=1.3:mail/p5-Net-IMAP-Simple-SSL \
		p5-URI-imaps>=0:mail/p5-URI-imaps
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
