PORTNAME=	oxidized
PORTVERSION=	0.29.1
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	nick@foobar.org
COMMENT=	Network device configuration backup tool
WWW=		https://github.com/ytti/oxidized

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-asetus>=0.4<1:devel/rubygem-asetus \
		rubygem-bcrypt_pbkdf>=1.0<2:security/rubygem-bcrypt_pbkdf \
		rubygem-ed25519>=1.2<2:security/rubygem-ed25519 \
		rubygem-net-ssh>=7.1,2<8,2:security/rubygem-net-ssh \
		rubygem-net-telnet>=0.2<1:security/rubygem-net-telnet \
		rubygem-psych3>=3.3<4:textproc/rubygem-psych3 \
		rubygem-rugged>=1.5<2:devel/rubygem-rugged \
		rubygem-slop>=4.10<5:devel/rubygem-slop

USES=		gem shebangfix

NO_ARCH=	yes
USE_RC_SUBR=	oxidized

PLIST_FILES=	bin/oxidized

SHEBANG_FILES=	extra/*.runit

USERS=		oxidized
GROUPS=		oxidized

SUB_LIST=	RUBY=${RUBY}

.include <bsd.port.mk>
