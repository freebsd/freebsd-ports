PORTNAME=	rabbitmq
DISTVERSION=	4.1.3
CATEGORIES=	net
MASTER_SITES=	https://github.com/rabbitmq/rabbitmq-server/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-server-generic-unix-${DISTVERSION}

MAINTAINER=	erlang@FreeBSD.org
# Co-maintainers: vvd@FreeBSD.org fsbruva@yahoo.com
COMMENT=	Erlang implementation of AMQP
WWW=		https://www.rabbitmq.com/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE-MPL-RabbitMQ

RUN_DEPENDS=	erlang-runtime${_ERLANG_VER}>=${_ERLANG_VER}:lang/erlang-runtime${_ERLANG_VER}

USES=		cpe shebangfix tar:xz
CPE_VENDOR=	pivotal_software
USE_LOCALE=	en_US.UTF-8
USE_RC_SUBR=	rabbitmq

NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST+=	_ERLANG_LIB=${_ERLANG_LIB}

USERS=		rabbitmq
GROUPS=		rabbitmq

PLIST_SUB=	VERSION=${DISTVERSION}

_ERLANG_VER=	27
_ERLANG_LIB=	erlang${_ERLANG_VER}

.include <bsd.port.options.mk>

do-extract:
	${MKDIR} ${WRKSRC}
	${TAR} -C ${WRKSRC} -xf ${DISTDIR}/${DISTFILES} --strip-components 1

post-patch:
	# ensure our OTP is always preferred over other installed versions
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin/env escript|${LOCALBASE}/lib/${_ERLANG_LIB}/bin/escript|' \
		${WRKSRC}/escript/*
	@${REINPLACE_CMD} -i '' -e 's|LOCALBASE|${LOCALBASE}|' \
		-e 's|_ERLANG_LIB|${_ERLANG_LIB}|' \
		${WRKSRC}/sbin/rabbitmq-defaults
	# # ensure docs match heir(7) paths
	# @${REINPLACE_CMD} -i '' \
	# 	-e 's|/etc/rabbitmq|${PREFIX}/etc/rabbitmq|g' \
	# 	-e 's|/var/lib|/var/db|g' \
	# 	${WRKSRC}/deps/rabbit/docs/*

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/rabbitmq_server-${DISTVERSION}
	(cd ${WRKSRC} && ${COPYTREE_BIN}   escript ${STAGEDIR}${PREFIX}/lib/rabbitmq_server-${DISTVERSION}/)
	(cd ${WRKSRC} && ${COPYTREE_BIN}      sbin ${STAGEDIR}${PREFIX}/lib/rabbitmq_server-${DISTVERSION}/)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} plugins ${STAGEDIR}${PREFIX}/lib/rabbitmq_server-${DISTVERSION}/)

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/rabbitmq
	@${MKDIR} ${STAGEDIR}/var/db/rabbitmq/mnesia
	@${MKDIR} ${STAGEDIR}/var/log/rabbitmq
	# ${INSTALL_DATA} ${WRKSRC}/deps/rabbit/docs/advanced.config.example \
	# ${STAGEDIR}${PREFIX}/etc/rabbitmq/advanced.config.sample
	# ${INSTALL_DATA} ${WRKSRC}/deps/rabbit/docs/rabbitmq.conf.example \
	# ${STAGEDIR}${PREFIX}/etc/rabbitmq/rabbitmq.conf.sample
.for _file in rabbitmq-defaults rabbitmq-diagnostics rabbitmq-env rabbitmq-plugins rabbitmq-queues rabbitmq-server rabbitmq-streams rabbitmq-upgrade rabbitmqctl vmware-rabbitmq
	${LN} -s ../lib/rabbitmq_server-${DISTVERSION}/sbin/${_file} ${STAGEDIR}${PREFIX}/sbin
.endfor
	${INSTALL_MAN} ${WRKSRC}/share/man/man5/*.5.gz  ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_MAN} ${WRKSRC}/share/man/man8/*.8.gz  ${STAGEDIR}${PREFIX}/share/man/man8
	# ${INSTALL} ${WRKSRC}/plugins/rabbitmq_management-*/priv/www/cli/rabbitmqadmin ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
