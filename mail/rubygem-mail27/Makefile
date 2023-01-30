PORTNAME=	mail
PORTVERSION=	2.7.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	27

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby email handler
WWW=		https://github.com/mikel/mail

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-mini_mime>=0.1.1:mail/rubygem-mini_mime \
		rubygem-net-imap>=0:mail/rubygem-net-imap \
		rubygem-net-pop>=0:mail/rubygem-net-pop \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	mail_project

PORTSCOUT=	limit:^2\.7\.

.include <bsd.port.mk>
