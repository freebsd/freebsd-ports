# New ports collection makefile for:	rabbitmq
# Date Created:				2008-07-11
# Whom:					Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rabbitmq
PORTVERSION=	1.3.0
CATEGORIES=	net
MASTER_SITES=	http://www.rabbitmq.com/releases/source/

MAINTAINER=	pneumann@gmail.com
COMMENT=	RabbitMQ is an implementation of AMQP

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang-lite
RUN_DEPENDS=	erlc:${PORTSDIR}/lang/erlang-lite

USE_GMAKE=	yes
USE_PYTHON=	yes
ALL_TARGET=	server
SCRIPTS_DIR=	${WRKSRC}/erlang/rabbit/scripts/
USE_RC_SUBR=	rabbitmq

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/default|${PREFIX}/etc/rabbitmq|g ; s|/var/lib|/var/db|g' \
		${SCRIPTS_DIR}/rabbitmq-multi ${SCRIPTS_DIR}/rabbitmq-server ${SCRIPTS_DIR}/rabbitmqctl

do-install:
	@${MKDIR} /var/log/rabbitmq /var/db/rabbitmq/mnesia ${PREFIX}/etc/rabbitmq
	@${FIND} ${WRKSRC} -name "*.bak" | ${XARGS} ${RM}
	@cd ${WRKSRC}/erlang/rabbit/dist && ${FIND} . \
		| ${CPIO} -pdmu ${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${INSTALL_SCRIPT} ${SCRIPTS_DIR}/rabbitmq-multi ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${SCRIPTS_DIR}/rabbitmq-server ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${SCRIPTS_DIR}/rabbitmqctl ${PREFIX}/bin

.include <bsd.port.mk>
