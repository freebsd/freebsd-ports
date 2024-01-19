PORTNAME=	gitlab-mail_room
PORTVERSION=	0.0.24
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Proxy email (gmail) from IMAP to a delivery method
WWW=		https://github.com/tpitale/mail_room

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-jwt>=2.0:www/rubygem-jwt \
		rubygem-net-imap>=0.2.1:mail/rubygem-net-imap \
		rubygem-oauth2>=1.4.4<3:net/rubygem-oauth2 \
		rubygem-redis4>=4<6:databases/rubygem-redis4 \
		rubygem-redis-namespace110>=1.8.2:databases/rubygem-redis-namespace110

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/mail_room

.include <bsd.port.mk>
