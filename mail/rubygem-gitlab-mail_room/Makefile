PORTNAME=	gitlab-mail_room
PORTVERSION=	0.0.27
PORTREVISION=	1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Proxy email (gmail) from IMAP to a delivery method
WWW=		https://gitlab.com/gitlab-org/ruby/gems/gitlab-mail_room

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-jwt>=2.0:www/rubygem-jwt \
		rubygem-net-imap>=0.2.1:mail/rubygem-net-imap \
		rubygem-oauth2-gitlab>=1.4.4<3:net/rubygem-oauth2-gitlab \
		rubygem-redis-gitlab>=5<6:databases/rubygem-redis-gitlab \
		rubygem-redis-namespace-gitlab>=1.8.2:databases/rubygem-redis-namespace-gitlab

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/mail_room

.include <bsd.port.mk>
