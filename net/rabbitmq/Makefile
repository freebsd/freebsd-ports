# New ports collection makefile for:	rabbitmq
# Date Created:				2008-07-11
# Whom:					Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rabbitmq
PORTVERSION=	2.8.4
CATEGORIES=	net
MASTER_SITES=	http://www.rabbitmq.com/releases/rabbitmq-server/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-server-${PORTVERSION}

MAINTAINER=	pneumann@gmail.com
COMMENT=	RabbitMQ is an implementation of AMQP

BUILD_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:${PORTSDIR}/devel/py-simplejson \
		xmlto:${PORTSDIR}/textproc/xmlto \
		unzip:${PORTSDIR}/archivers/unzip \
		zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

USE_GMAKE=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	rabbitmq

USERS=	rabbitmq
GROUPS=	rabbitmq

PLIST_SUB=	"VERSION=${PORTVERSION}"

MAN1=		rabbitmq-server.1 rabbitmqctl.1 rabbitmq-plugins.1
MAN5=		rabbitmq-env.conf.5
MANCOMPRESSED=	yes

SCRIPTS_DIR=	${WRKSRC}/scripts/
MAKE_ENV+=	TARGET_DIR="${PREFIX}/lib/erlang/lib/rabbitmq_server-${PORTVERSION}" SBIN_DIR="${PREFIX}/sbin/" \
		MAN_DIR="${PREFIX}/man"

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/rabbitmq|${PREFIX}/etc/rabbitmq|g ; s|/var/lib|/var/db|g ; s|erl|${LOCALBASE}/bin/erl|g' \
		${SCRIPTS_DIR}/rabbitmq-server ${SCRIPTS_DIR}/rabbitmqctl \
		${SCRIPTS_DIR}/rabbitmq-env ${SCRIPTS_DIR}/rabbitmq-plugins \
		${SCRIPTS_DIR}/rabbitmq-defaults
	@${FIND} ${WRKSRC} -name "*.bak" -delete

pre-install:
	@${FIND} ${WRKSRC}/ebin ${WRKSRC}/include -type d | \
		${XARGS} ${CHMOD} 0755
	@${FIND} ${WRKSRC}/ebin ${WRKSRC}/include -type f | \
		${XARGS} ${CHMOD} 0644
	@${MKDIR} ${PREFIX}/etc/rabbitmq

post-install:
	@${MKDIR} /var/db/rabbitmq/mnesia
	@${MKDIR} /var/log/rabbitmq
	@${CHOWN} -R rabbitmq:rabbitmq /var/db/rabbitmq
	@${CHOWN} -R rabbitmq:rabbitmq /var/log/rabbitmq

.include <bsd.port.mk>
