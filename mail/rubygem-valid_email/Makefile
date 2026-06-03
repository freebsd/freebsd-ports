PORTNAME=	valid_email
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	ActiveModel Validation for email
WWW=		https://github.com/hallelujah/valid_email

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel-gitlab>=0:databases/rubygem-activemodel-gitlab \
		rubygem-mail-gitlab>=2.6.1:mail/rubygem-mail-gitlab \
		rubygem-simpleidn>=0:dns/rubygem-simpleidn

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
