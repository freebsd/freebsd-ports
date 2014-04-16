# $FreeBSD$

PORTNAME=	fluentd
PORTVERSION=	0.10.35
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Fluent event collector

BROKEN=		Requires http_parser version 0.5.1 while version 0.6 is installed

RUN_DEPENDS=	\
	rubygem-msgpack>=0.5.4:${PORTSDIR}/devel/rubygem-msgpack \
	rubygem-json>=1.4.3:${PORTSDIR}/devel/rubygem-json \
	rubygem-yajl-ruby>=1.0:${PORTSDIR}/devel/rubygem-yajl-ruby \
	rubygem-cool.io>=1.1.0:${PORTSDIR}/devel/rubygem-cool.io \
	rubygem-http_parser.rb>=0.5.1:${PORTSDIR}/net/rubygem-http_parser.rb

USE_RUBY=	yes
USE_RUBYGEMS=	yes
PLIST_FILES=	bin/fluent-cat bin/fluent-debug bin/fluent-gem bin/fluentd \
		"@exec ${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 775 /var/run/fluentd" \
		"@unexec ${RMDIR} /var/run/fluentd 2>/dev/null || true"
RUBYGEM_AUTOPLIST=	yes
USE_RC_SUBR=	fluentd
USERS=		fluentd
GROUPS=		fluentd
SUB_LIST+=	USER=${USERS} GROUP=${GROUPS}

.include <bsd.port.mk>
