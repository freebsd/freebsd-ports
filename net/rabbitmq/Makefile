# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	rabbitmq
PORTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.rabbitmq.com/releases/rabbitmq-server/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-server-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	RabbitMQ is an implementation of AMQP

LICENSE=	MPL

BUILD_DEPENDS=	erl:lang/erlang \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:devel/py-simplejson \
		xmlto:textproc/xmlto \
		unzip:archivers/unzip \
		zip:archivers/zip \
		rsync:net/rsync
RUN_DEPENDS=	erl:lang/erlang

OPTIONS_DEFINE=	ADMIN
OPTIONS_SUB=	yes

ADMIN_DESC=	Install rabbitmqadmin script
ADMIN_USES=	python:run

ALL_TARGET=	all manpages
USES=		cpe gmake python:build tar:xz
USE_RC_SUBR=	rabbitmq
NO_ARCH=	yes

USERS=		rabbitmq
GROUPS=		rabbitmq

PLIST_SUB=	VERSION=${PORTVERSION}

CPE_VENDOR=	pivotal_software

REINPLACE_ARGS=	-i ""
SCRIPTS_DIR=	${WRKSRC}/scripts/
MAKE_ARGS+=	PYTHON=${PYTHON_CMD}
MAKE_ENV+=	TARGET_DIR="${STAGEDIR}${PREFIX}/lib/erlang/lib/rabbitmq_server-${PORTVERSION}" \
		SBIN_DIR="${STAGEDIR}${PREFIX}/sbin/" \
		MAN_DIR="${STAGEDIR}${PREFIX}/man" \
		DOC_INSTALL_DIR="${STAGEDIR}${EXAMPLESDIR}"

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/rabbitmq|${PREFIX}/etc/rabbitmq|g ; s|/var/lib|/var/db|g ; s|$${ERL_DIR}erl|${PREFIX}/bin/erl|g' \
		${SCRIPTS_DIR}/rabbitmq-server \
		${SCRIPTS_DIR}/rabbitmqctl \
		${SCRIPTS_DIR}/rabbitmq-env \
		${SCRIPTS_DIR}/rabbitmq-plugins \
		${SCRIPTS_DIR}/rabbitmq-defaults \
		${WRKSRC}/docs/rabbitmq-env.conf.5.xml

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/rabbitmq
	@${MKDIR} ${STAGEDIR}/var/db/rabbitmq/mnesia
	@${MKDIR} ${STAGEDIR}/var/log/rabbitmq
	${INSTALL_DATA} ${WRKSRC}/docs/rabbitmq.config.example \
		${STAGEDIR}${PREFIX}/etc/rabbitmq/rabbitmq.config.sample
.for _file in rabbitmq-defaults rabbitmq-env rabbitmq-plugins rabbitmq-server rabbitmqctl
	${LN} -s ../lib/erlang/lib/rabbitmq_server-${PORTVERSION}/sbin/${_file} ${STAGEDIR}${PREFIX}/sbin
.endfor
.for _file in rabbitmq-plugins.1 rabbitmq-server.1 rabbitmqctl.1
	${INSTALL_MAN} ${WRKSRC}/docs/${_file} ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/docs/rabbitmq-env.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

post-install-ADMIN-on:
	${INSTALL} ${WRKSRC}/deps/rabbitmq_management/bin/rabbitmqadmin ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
