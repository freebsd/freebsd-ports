# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	rabbitmq
PORTVERSION=	3.7.5
CATEGORIES=	net
MASTER_SITES=	https://github.com/rabbitmq/rabbitmq-server/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-server-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	RabbitMQ is an implementation of AMQP

LICENSE=	MPL11
LICENSE_FILE=	${WRKSRC}/LICENSE-MPL-RabbitMQ

BUILD_DEPENDS=	erlang-runtime19>=19.3:lang/erlang-runtime19 \
		elixir:lang/elixir \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:devel/py-simplejson \
		xmlto:textproc/xmlto \
		zip:archivers/zip \
		rsync:net/rsync
RUN_DEPENDS=	erlang-runtime19>=19.3:lang/erlang-runtime19

OPTIONS_DEFINE=	ADMIN
OPTIONS_SUB=	yes

ADMIN_DESC=	Install rabbitmqadmin script
ADMIN_USES=	python
ADMIN_USES_OFF=	python:build

ALL_TARGET=	all manpages
USES=		cpe gmake shebangfix tar:xz
USE_LOCALE=	en_US.UTF-8
USE_RC_SUBR=	rabbitmq
NO_ARCH=	yes

USERS=		rabbitmq
GROUPS=		rabbitmq

PLIST_SUB=	VERSION=${PORTVERSION}

CPE_VENDOR=	pivotal_software

REINPLACE_ARGS=	-i ""
SCRIPTS_DIR=	${WRKSRC}/deps/rabbit/scripts
SHEBANG_FILES=	deps/rabbitmq_management/bin/rabbitmqadmin
MAKE_ARGS+=	PYTHON=${PYTHON_CMD}
MAKE_ENV+=	PATH="${LOCALBASE}/lib/erlang19/bin:${PATH}" \
		TARGET_DIR="${STAGEDIR}${PREFIX}/lib/erlang/lib/rabbitmq_server-${PORTVERSION}" \
		SBIN_DIR="${STAGEDIR}${PREFIX}/sbin/" \
		MAN_DIR="${STAGEDIR}${PREFIX}/man" \
		DOC_INSTALL_DIR="${STAGEDIR}${EXAMPLESDIR}" \
		VERSION="${PORTVERSION}"

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/rabbitmq|${PREFIX}/etc/rabbitmq|g ; s|/var/lib|/var/db|g ; s|$${ERL_DIR}erl|${PREFIX}/lib/erlang19/bin/erl|g' \
		${SCRIPTS_DIR}/rabbitmq-server \
		${SCRIPTS_DIR}/rabbitmqctl \
		${SCRIPTS_DIR}/rabbitmq-env \
		${SCRIPTS_DIR}/rabbitmq-plugins \
		${SCRIPTS_DIR}/rabbitmq-defaults \
		${WRKSRC}/deps/rabbit/docs/rabbitmq-env.conf.5

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/rabbitmq
	@${MKDIR} ${STAGEDIR}/var/db/rabbitmq/mnesia
	@${MKDIR} ${STAGEDIR}/var/log/rabbitmq
	${INSTALL_DATA} ${WRKSRC}/deps/rabbit/docs/rabbitmq.config.example \
	${STAGEDIR}${PREFIX}/etc/rabbitmq/rabbitmq.config.sample
.for _file in rabbitmq-defaults rabbitmq-env rabbitmq-plugins rabbitmq-server rabbitmqctl
	${LN} -s ../lib/erlang/lib/rabbitmq_server-${PORTVERSION}/sbin/${_file} ${STAGEDIR}${PREFIX}/sbin
.endfor
.for _file in rabbitmq-plugins.8 rabbitmq-server.8 rabbitmqctl.8
	${INSTALL_MAN} ${WRKSRC}/deps/rabbit/docs/${_file} ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/deps/rabbit/docs/rabbitmq-env.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

post-install-ADMIN-on:
	${INSTALL} ${WRKSRC}/deps/rabbitmq_management/bin/rabbitmqadmin ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
