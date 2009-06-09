# New ports collection makefile for:	rabbitmq
# Date Created:				2008-07-11
# Whom:					Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rabbitmq
PORTVERSION=	1.5.5
CATEGORIES=	net
MASTER_SITES=	http://www.rabbitmq.com/releases/rabbitmq-server/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-server-${PORTVERSION}

MAINTAINER=	pneumann@gmail.com
COMMENT=	RabbitMQ is an implementation of AMQP

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang-lite \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:${PORTSDIR}/devel/py-simplejson
RUN_DEPENDS=	erlc:${PORTSDIR}/lang/erlang-lite

USE_GMAKE=	yes
USE_PYTHON=	yes
MAKE_ENV+=	TARGET_DIR="${PREFIX}/lib/erlang/lib/rabbitmq_server-${PORTVERSION}" SBIN_DIR="${PREFIX}/sbin/" \
		MAN_DIR="${PREFIX}/man"
SCRIPTS_DIR=	${WRKSRC}/scripts/
USE_RC_SUBR=	rabbitmq
PLIST_SUB=	"VERSION=${PORTVERSION}"
SUB_FILES=	pkg-install
RABBITMQ_USER=	rabbitmq
RABBITMQ_GROUP=	${RABBITMQ_USER}

MAN1=		rabbitmq-multi.1 rabbitmq-server.1 rabbitmqctl.1
MAN5=		rabbitmq.conf.5
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/default|${PREFIX}/etc/rabbitmq|g ; s|/var/lib|/var/db|g ; s|erl|${PREFIX}/bin/erl|g' \
		${SCRIPTS_DIR}/rabbitmq-multi ${SCRIPTS_DIR}/rabbitmq-server ${SCRIPTS_DIR}/rabbitmqctl
	@${FIND} ${WRKSRC} -name "*.bak" | ${XARGS} ${RM}

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${FIND} ${WRKSRC}/ebin ${WRKSRC}/include -type d | \
		${XARGS} ${CHMOD} 0755
	@${FIND} ${WRKSRC}/ebin ${WRKSRC}/include -type f | \
		${XARGS} ${CHMOD} 0644

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
