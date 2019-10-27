# $FreeBSD$

PORTNAME=	fluentd
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Fluent event collector

LICENSE=	APACHE20

RUN_DEPENDS=	\
	rubygem-dig_rb>=1.0.0:devel/rubygem-dig_rb \
	rubygem-msgpack>=0.7.0:devel/rubygem-msgpack \
	rubygem-yajl-ruby>=1.0:devel/rubygem-yajl-ruby \
	rubygem-cool.io>=1.4.5:devel/rubygem-cool.io \
	rubygem-serverengine>=2.0.4:net/rubygem-serverengine \
	rubygem-http_parser.rb>=0.5.1:net/rubygem-http_parser.rb \
	rubygem-sigdump>=0.2.2:devel/rubygem-sigdump \
	rubygem-strptime>=0.2.2:devel/rubygem-strptime \
	rubygem-tzinfo1>=1.0:devel/rubygem-tzinfo1 \
	rubygem-tzinfo-data>=1.0.0:devel/rubygem-tzinfo-data

USE_RUBY=	yes
PLIST_FILES=	bin/fluent-cat bin/fluent-debug bin/fluent-gem bin/fluentd \
		bin/fluent-binlog-reader bin/fluent-ca-generate \
		bin/fluent-plugin-config-format bin/fluent-plugin-generate \
		"@sample etc/fluentd/fluent.conf.sample"
PLIST_DIRS=	etc/fluentd/plugin
USES=		gem
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
