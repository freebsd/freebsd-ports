# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-Delete
PORTVERSION=	2.00.1
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C|\.([0-9])$|\1|}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Delete Messages from Folders

RUN_DEPENDS=	p5-Email-Folder>=0.84:mail/p5-Email-Folder \
		p5-Email-FolderType>=0.7:mail/p5-Email-FolderType \
		p5-Email-LocalDelivery>=0.21.3:mail/p5-Email-LocalDelivery \
		p5-Email-Simple>=1.92:mail/p5-Email-Simple \
		p5-File-Find-Rule>=0.28:devel/p5-File-Find-Rule
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
