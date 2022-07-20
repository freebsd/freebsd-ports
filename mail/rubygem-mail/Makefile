PORTNAME=	mail
PORTVERSION=	2.7.1
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby email handler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-mini_mime>=0.1.1:mail/rubygem-mini_mime

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	mail_project

.include <bsd.port.pre.mk>

# See https://github.com/mikel/mail/pull/1439
.if ${RUBY_VER} >= 3.1
RUN_DEPENDS+=	rubygem-net-imap>=0:mail/rubygem-net-imap \
		rubygem-net-pop>=0:mail/rubygem-net-pop \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp
.endif

.include <bsd.port.post.mk>
