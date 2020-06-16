# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	oxidized
PORTVERSION=	0.28.0
PORTREVISION=	1
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	nick@foobar.org
COMMENT=	Network device configuration backup tool

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-asetus>=0.1<1:devel/rubygem-asetus \
		rubygem-bcrypt_pbkdf>=1.0<2:security/rubygem-bcrypt_pbkdf \
		rubygem-ed25519>=1.2<2:security/rubygem-ed25519 \
		rubygem-net-ssh5>=5<6,2:security/rubygem-net-ssh5 \
		rubygem-net-telnet>=0.2<1:security/rubygem-net-telnet \
		rubygem-rugged>=1.0:devel/rubygem-rugged \
		rubygem-slop>=4.6<5:devel/rubygem-slop

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes
USE_RC_SUBR=	oxidized

PLIST_FILES=	bin/oxidized

SHEBANG_FILES=	extra/*.runit

USERS=		oxidized
GROUPS=		oxidized

SUB_LIST=	RUBY=${RUBY}

.include <bsd.port.mk>
