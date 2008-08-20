# New ports collection makefile for:	rabbitmq
# Date Created:				2008-07-11
# Whom:					Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rabbitmq
PORTVERSION=	1.4.0
CATEGORIES=	net
MASTER_SITES=	http://www.rabbitmq.com/releases/rabbitmq-server/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-server-${PORTVERSION}

MAINTAINER=	pneumann@gmail.com
COMMENT=	RabbitMQ is an implementation of AMQP

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang-lite
RUN_DEPENDS=	erlc:${PORTSDIR}/lang/erlang-lite

USE_GMAKE=	yes
USE_PYTHON=	yes
MAKE_ENV+=	TARGET_DIR="${PREFIX}/lib/erlang/lib/rabbitmq-${PORTVERSION}" SBIN_DIR="${PREFIX}/sbin/"
SCRIPTS_DIR=	${WRKSRC}/scripts/
USE_RC_SUBR=	rabbitmq
PLIST_SUB=	"VERSION=${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/default|${PREFIX}/etc/rabbitmq|g ; s|/var/lib|/var/db|g' \
		${SCRIPTS_DIR}/rabbitmq-multi ${SCRIPTS_DIR}/rabbitmq-server ${SCRIPTS_DIR}/rabbitmqctl

	@${MKDIR} /var/log/rabbitmq /var/db/rabbitmq/mnesia ${PREFIX}/etc/rabbitmq
	@${FIND} ${WRKSRC} -name "*.bak" | ${XARGS} ${RM}

.include <bsd.port.mk>
