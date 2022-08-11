PORTNAME=	Email-Folder-POP3
PORTVERSION=	1.015
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Email::Folder access to POP3 folders

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-Folder>=0:mail/p5-Email-Folder \
		p5-Email-FolderType-Net>=0:mail/p5-Email-FolderType-Net \
		p5-URI>=0:net/p5-URI

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
