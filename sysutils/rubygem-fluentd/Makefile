# $FreeBSD$

PORTNAME=	fluentd
PORTVERSION=	0.12.14
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Fluent event collector

LICENSE=	APACHE20

RUN_DEPENDS=	\
	rubygem-msgpack>=0.5.11:devel/rubygem-msgpack \
	rubygem-json>=1.4.3:devel/rubygem-json \
	rubygem-yajl-ruby>=1.0:devel/rubygem-yajl-ruby \
	rubygem-cool.io>=1.2.2:devel/rubygem-cool.io \
	rubygem-http_parser.rb>=0.5.1:net/rubygem-http_parser.rb \
	rubygem-sigdump>=0.2.2:devel/rubygem-sigdump \
	rubygem-tzinfo>=1.0.0:devel/rubygem-tzinfo

USE_RUBY=	yes
PLIST_FILES=	bin/fluent-cat bin/fluent-debug bin/fluent-gem bin/fluentd \
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
