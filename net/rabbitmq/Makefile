# Created by: Phillip Neumann <pneumann@gmail.com>

PORTNAME=	rabbitmq
DISTVERSION=	3.9.10
CATEGORIES=	net
MASTER_SITES=	https://github.com/rabbitmq/rabbitmq-server/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-server-${PORTVERSION}

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Erlang implementation of AMQP

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE-MPL-RabbitMQ

BUILD_DEPENDS=	erlang-runtime${ERLANG_VER}>=${ERLANG_VER}.0:lang/erlang-runtime${ERLANG_VER} \
		elixir>=1.10:lang/elixir \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:devel/py-simplejson@${PY_FLAVOR} \
		xmlto:textproc/xmlto \
		zip:archivers/zip \
		rsync:net/rsync
RUN_DEPENDS=	erlang-runtime${ERLANG_VER}>=${ERLANG_VER}.0:lang/erlang-runtime${ERLANG_VER}

USES=		cpe gmake shebangfix tar:xz
USE_LOCALE=	en_US.UTF-8
USE_RC_SUBR=	rabbitmq
NO_ARCH=	yes

OPTIONS_DEFINE=	ADMIN
OPTIONS_SUB=	yes

ADMIN_DESC=	Install rabbitmqadmin script
ADMIN_USES=	python
ADMIN_USES_OFF=	python:build

ALL_TARGET=	install

USERS=		rabbitmq
GROUPS=		rabbitmq

SUB_LIST+=	ERLANG_LIB=${ERLANG_LIB}

PLIST_SUB=	VERSION=${PORTVERSION}

CPE_VENDOR=	pivotal_software

REINPLACE_ARGS=	-i ""
SHEBANG_FILES=	deps/rabbitmq_management/bin/rabbitmqadmin
MAKE_ARGS+=	PYTHON=${PYTHON_CMD}
MAKE_ENV+=	PATH="${LOCALBASE}/lib/${ERLANG_LIB}/bin:${PATH}" \
		RMQ_LIBDIR="${PREFIX}/lib" \
		MANDIR="${PREFIX}/man" \
		DESTDIR="${STAGEDIR}"

MAKE_JOBS_UNSAFE=	yes

ERLANG_VER=	24
ERLANG_LIB=	erlang${ERLANG_VER}

.include <bsd.port.options.mk>

post-patch:
	# ensure our OTP is always preferred over other installed versions
	@${REINPLACE_CMD} -e 's|LOCALBASE|${LOCALBASE}|' \
		-e 's|ERLANG_LIB|${ERLANG_LIB}|' \
		${WRKSRC}/deps/rabbit/scripts/rabbitmq-defaults
	# ensure docs match heir(7) paths
	@${REINPLACE_CMD} -i '' \
		-e 's|/etc/rabbitmq|${PREFIX}/etc/rabbitmq|g' \
		-e 's|/var/lib|/var/db|g' \
		${WRKSRC}/deps/rabbit/docs/*

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/rabbitmq
	@${MKDIR} ${STAGEDIR}/var/db/rabbitmq/mnesia
	@${MKDIR} ${STAGEDIR}/var/log/rabbitmq
	${INSTALL_DATA} ${WRKSRC}/deps/rabbit/docs/advanced.config.example \
	${STAGEDIR}${PREFIX}/etc/rabbitmq/advanced.config.sample
	${INSTALL_DATA} ${WRKSRC}/deps/rabbit/docs/rabbitmq.conf.example \
	${STAGEDIR}${PREFIX}/etc/rabbitmq/rabbitmq.conf.sample
.for _file in rabbitmq-defaults rabbitmq-diagnostics rabbitmq-env rabbitmq-plugins rabbitmq-server rabbitmq-streams rabbitmq-upgrade rabbitmqctl
	${LN} -s ../lib/rabbitmq_server-${PORTVERSION}/sbin/${_file} ${STAGEDIR}${PREFIX}/sbin
.endfor
	${INSTALL_MAN} ${WRKSRC}/deps/rabbit/docs/*.8  ${STAGEDIR}${MAN1PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/deps/rabbit/docs/rabbitmq-env.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

post-install-ADMIN-on:
	${INSTALL} ${WRKSRC}/deps/rabbitmq_management/bin/rabbitmqadmin ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
