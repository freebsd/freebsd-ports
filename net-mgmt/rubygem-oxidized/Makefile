# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	oxidized
PORTVERSION=	0.21.0
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	nick@foobar.org
COMMENT=	Network device configuration backup tool

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-asetus>=0.1:devel/rubygem-asetus \
		rubygem-net-ssh>=4.1.0:security/rubygem-net-ssh \
		rubygem-rugged>=0.21.4:devel/rubygem-rugged \
		rubygem-slop3>=3.5:devel/rubygem-slop3

NO_ARCH=	yes

USE_RC_SUBR=	oxidized

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	extra/*.runit

USERS=		oxidized
GROUPS=		oxidized

SUB_LIST=	PREFIX=${PREFIX} \
		RUBY=${RUBY}

PLIST_FILES=	bin/oxidized

.include <bsd.port.mk>
