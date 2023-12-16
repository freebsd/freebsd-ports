PORTNAME=	fluentd
PORTVERSION=	1.16.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Fluent event collector
WWW=		https://fluentd.org/

LICENSE=	APACHE20

RUN_DEPENDS=	\
	rubygem-bundler>=0:sysutils/rubygem-bundler \
	rubygem-cool.io>=1.4.5<2.0.0:devel/rubygem-cool.io \
	rubygem-http_parser.rb>=0.5.1<0.9.0:net/rubygem-http_parser.rb \
	rubygem-msgpack>=1.3.1<2.0.0:devel/rubygem-msgpack \
	rubygem-serverengine>=2.2.5<3.0.0:net/rubygem-serverengine \
	rubygem-sigdump>=0.2.2<0.3:devel/rubygem-sigdump \
	rubygem-strptime>=0.2.2<1.0.0:devel/rubygem-strptime \
	rubygem-tzinfo1>=1.0<3.0:devel/rubygem-tzinfo1 \
	rubygem-tzinfo-data>=1.0<2:devel/rubygem-tzinfo-data \
	rubygem-webrick>=1.4.2<1.9.0:www/rubygem-webrick \
	rubygem-yajl-ruby>=1.0<2:devel/rubygem-yajl-ruby

PLIST_FILES=	bin/fluent-cap-ctl bin/fluent-cat bin/fluent-ctl \
		bin/fluent-debug bin/fluent-gem bin/fluentd \
		bin/fluent-binlog-reader bin/fluent-ca-generate \
		bin/fluent-plugin-config-format bin/fluent-plugin-generate \
		"@sample etc/fluentd/fluent.conf.sample"
PLIST_DIRS=	etc/fluentd/plugin
USES=		cpe gem
USE_RC_SUBR=	fluentd
USERS=		fluentd
GROUPS=		fluentd
SUB_LIST+=	USER=${USERS} GROUP=${GROUPS} RUBY=${RUBY}
NO_ARCH=	YES
NO_LATEST_LINK=	YES

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fluentd/plugin
	${CP} ${WRKSRC}/fluent.conf.sample ${STAGEDIR}${PREFIX}/etc/fluentd/

.include <bsd.port.mk>
