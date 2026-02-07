PORTNAME=	extended_email_reply_parser
PORTVERSION=	0.5.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extended version of GitHub's email_reply_parser
WWW=		https://github.com/fiedl/extended_email_reply_parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport71>=0:devel/rubygem-activesupport71 \
		rubygem-charlock_holmes>=0:textproc/rubygem-charlock_holmes \
		rubygem-email_reply_parser>=0.5.9<0.6:mail/rubygem-email_reply_parser \
		rubygem-mail>=0,2:mail/rubygem-mail

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
