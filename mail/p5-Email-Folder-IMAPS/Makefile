# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-Folder-IMAPS
PORTVERSION=	1.105
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Email::Folder access to IMAP over SSL folders

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-Folder-IMAP>=1.102:mail/p5-Email-Folder-IMAP \
		p5-Net-IMAP-Simple-SSL>=1.3:mail/p5-Net-IMAP-Simple-SSL \
		p5-URI-imap>=0:mail/p5-URI-imap \
		p5-URI-imaps>=0:mail/p5-URI-imaps

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
