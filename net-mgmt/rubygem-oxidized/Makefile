PORTNAME=	oxidized
PORTVERSION=	0.34.3
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	nick@foobar.org
COMMENT=	Network device configuration backup tool
WWW=		https://github.com/ytti/oxidized

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-asetus>=0.4<1:devel/rubygem-asetus \
		rubygem-bcrypt_pbkdf>=1.0<2:security/rubygem-bcrypt_pbkdf \
		rubygem-ed25519>=1.2<2:security/rubygem-ed25519 \
		rubygem-net-ftp>=0.2:ftp/rubygem-net-ftp \
		rubygem-net-http-digest_auth>=1.4<2:www/rubygem-net-http-digest_auth \
		rubygem-net-scp>=4.1:security/rubygem-net-scp \
		rubygem-net-ssh>=7.3,2<8,2:security/rubygem-net-ssh \
		rubygem-net-telnet>=0.2<1:security/rubygem-net-telnet \
		rubygem-ostruct>=0.6<1:devel/rubygem-ostruct \
		rubygem-psych>=5.0<6:textproc/rubygem-psych \
		rubygem-rugged>=1.6<2:devel/rubygem-rugged \
		rubygem-semantic_logger>=4.17.0:devel/rubygem-semantic_logger \
		rubygem-slop>=4.6<5:devel/rubygem-slop \
		rubygem-syslog>=0.3.0:devel/rubygem-syslog \
		rubygem-syslog_protocol>=0.9.2:devel/rubygem-syslog_protocol \

USES=		gem shebangfix

NO_ARCH=	yes
USE_RC_SUBR=	oxidized

PLIST_FILES=	bin/oxidized

SHEBANG_FILES=	extra/*.runit

USERS=		oxidized
GROUPS=		oxidized

SUB_LIST=	RUBY=${RUBY}

.include <bsd.port.mk>
