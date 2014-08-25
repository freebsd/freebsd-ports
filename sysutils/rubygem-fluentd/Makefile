# $FreeBSD$

PORTNAME=	fluentd
PORTVERSION=	0.10.53
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Fluent event collector

RUN_DEPENDS=	\
	rubygem-cool.io>=1.1.1:${PORTSDIR}/devel/rubygem-cool.io \
	rubygem-http_parser.rb>=0.5.1:${PORTSDIR}/net/rubygem-http_parser.rb \
	rubygem-json>=1.4.3:${PORTSDIR}/devel/rubygem-json \
	rubygem-msgpack>=0.5.4:${PORTSDIR}/devel/rubygem-msgpack \
	rubygem-sigdump>=0.2.2:${PORTSDIR}/devel/rubygem-sigdump \
	rubygem-yajl-ruby>=1.0:${PORTSDIR}/devel/rubygem-yajl-ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
PLIST_FILES=	bin/fluent-cat bin/fluent-debug bin/fluent-gem bin/fluentd \
		"@sample etc/fluentd/fluent.conf.sample"
PLIST_DIRS=	etc/fluentd/plugin etc/fluentd
RUBYGEM_AUTOPLIST=	yes
USE_RC_SUBR=	fluentd
USERS=		fluentd
GROUPS=		fluentd
SUB_LIST+=	USER=${USERS} GROUP=${GROUPS} RUBY=${RUBY}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fluentd/plugin
	${CP} ${WRKSRC}/fluent.conf.sample ${STAGEDIR}${PREFIX}/etc/fluentd/

.include <bsd.port.mk>
