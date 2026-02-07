PORTNAME=	mail
PORTVERSION=	2.9.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby email handler
WWW=		https://github.com/mikel/mail

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-logger-gitlab>=0:devel/rubygem-logger-gitlab \
		rubygem-mini_mime>=0.1.1:mail/rubygem-mini_mime \
		rubygem-net-imap>=0:mail/rubygem-net-imap \
		rubygem-net-pop>=0:mail/rubygem-net-pop \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp

USES=		cpe gem

CPE_VENDOR=	mail_project

NO_ARCH=	yes

.include <bsd.port.mk>
