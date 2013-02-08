# $FreeBSD$

PORTNAME=	fluentd
PORTVERSION=	0.10.30
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Fluent event collector

RUN_DEPENDS=	\
	rubygem-msgpack>=0.4.4:${PORTSDIR}/devel/rubygem-msgpack \
	rubygem-json>=1.4.3:${PORTSDIR}/devel/rubygem-json \
	rubygem-yajl-ruby>=1.0:${PORTSDIR}/devel/rubygem-yajl-ruby \
	rubygem-cool.io>=1.1.0:${PORTSDIR}/devel/rubygem-cool.io \
	rubygem-http_parser.rb>=0.5.1:${PORTSDIR}/net/rubygem-http_parser.rb

USE_RUBY=	yes
#RUBY_VER=	1.9	# Please set RUBY_DEFAULT_VER=1.9 in /etc/make.conf
USE_RUBYGEMS=	yes
PLIST_FILES=	bin/fluent-cat bin/fluent-debug bin/fluent-gem bin/fluentd \
		"@exec ${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 775 /var/run/fluentd" \
		"@unexec ${RMDIR} /var/run/fluentd 2>/dev/null || true"
RUBYGEM_AUTOPLIST=	yes
USE_RC_SUBR=	fluentd
USERS=		fluentd
GROUPS=		fluentd
SUB_LIST+=	USER=${USERS} GROUP=${GROUPS}

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == "1.8"
IGNORE=		requires Ruby 1.9, please install this first
.endif

post-install:
	${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 775 /var/run/fluentd

.include <bsd.port.post.mk>
