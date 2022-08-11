PORTNAME=	gitlab-mail_room
PORTVERSION=	0.0.19
PORTREVISION=	1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Proxy email (gmail) from IMAP to a delivery method

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-io-wait01>=0.1.0<0.2:devel/rubygem-io-wait01 \
		rubygem-jwt>=2.0:www/rubygem-jwt \
		rubygem-net-imap>=0.2.1:mail/rubygem-net-imap \
		rubygem-oauth21>=1.4.4<1.5:net/rubygem-oauth21

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/mail_room

.include <bsd.port.mk>
