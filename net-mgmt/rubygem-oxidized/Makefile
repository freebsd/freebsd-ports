# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	oxidized
PORTVERSION=	0.26.3
PORTREVISION=	1
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	nick@foobar.org
COMMENT=	Network device configuration backup tool

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-asetus>=0.1:devel/rubygem-asetus \
		rubygem-net-ssh>=5:security/rubygem-net-ssh \
		rubygem-net-telnet>=0.1.1:security/rubygem-net-telnet \
		rubygem-rugged>=0.21.4:devel/rubygem-rugged \
		rubygem-slop3>=3.5:devel/rubygem-slop3

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
