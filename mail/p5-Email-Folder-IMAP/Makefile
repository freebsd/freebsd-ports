# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-Folder-IMAP
PORTVERSION=	1.105
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Email::Folder Access to IMAP Folders

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Email-Folder>=0:mail/p5-Email-Folder \
		p5-Email-FolderType-Net>=0:mail/p5-Email-FolderType-Net \
		p5-Net-IMAP-Simple>=0.95:mail/p5-Net-IMAP-Simple \
		p5-URI>=0:net/p5-URI \
		p5-URI-imap>=0:mail/p5-URI-imap
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
