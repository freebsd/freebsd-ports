# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-Delete
PORTVERSION=	2.002
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Delete Messages from Folders

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-Folder>=0:mail/p5-Email-Folder \
		p5-Email-FolderType>=0:mail/p5-Email-FolderType \
		p5-Email-LocalDelivery>=0:mail/p5-Email-LocalDelivery \
		p5-Email-Simple>=0:mail/p5-Email-Simple

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
