PORTNAME=	mail_room
PORTVERSION=	0.11.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Proxy email (gmail) from IMAP to a delivery method
WWW=		https://github.com/tpitale/mail_room

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-jwt>=2.0:www/rubygem-jwt \
		rubygem-net-imap>=0.2.1:mail/rubygem-net-imap \
		rubygem-oauth2>=1.4.4<3:net/rubygem-oauth2

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/mail_room

.include <bsd.port.mk>
