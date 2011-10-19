# New ports collection makefile for:	rabbitmq
# Date Created:				2008-07-11
# Whom:					Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rabbitmq
PORTVERSION=	2.6.1
CATEGORIES=	net
MASTER_SITES=	http://www.rabbitmq.com/releases/rabbitmq-server/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-server-${PORTVERSION}

MAINTAINER=	pneumann@gmail.com
COMMENT=	RabbitMQ is an implementation of AMQP

BUILD_DEPENDS=	erlang-lite>=r14b03,1:${PORTSDIR}/lang/erlang-lite \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:${PORTSDIR}/devel/py-simplejson \
		xmlto:${PORTSDIR}/textproc/xmlto
RUN_DEPENDS=	erlang-lite>=r14b03,1:${PORTSDIR}/lang/erlang-lite \
		sudo:${PORTSDIR}/security/sudo

USE_GMAKE=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	rabbitmq

RABBITMQ_GID=	135
RABBITMQ_GROUP=	rabbitmq
RABBITMQ_UID=	135
RABBITMQ_USER=	rabbitmq

PLIST_SUB=	"VERSION=${PORTVERSION}"

SUB_FILES=	pkg-install
SUB_LIST=	RABBITMQ_GID=${RABBITMQ_GID} \
		RABBITMQ_GROUP=${RABBITMQ_GROUP} \
		RABBITMQ_UID=${RABBITMQ_UID} \
		RABBITMQ_USER=${RABBITMQ_USER}

MAN1=		rabbitmq-server.1 rabbitmqctl.1
MAN5=		rabbitmq-env.conf.5
MANCOMPRESSED=	yes

SCRIPTS_DIR=	${WRKSRC}/scripts/
MAKE_ENV+=	TARGET_DIR="${PREFIX}/lib/erlang/lib/rabbitmq_server-${PORTVERSION}" SBIN_DIR="${PREFIX}/sbin/" \
		MAN_DIR="${PREFIX}/man"

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/rabbitmq|${PREFIX}/etc/rabbitmq|g ; s|/var/lib|/var/db|g ; s|erl|${LOCALBASE}/bin/erl|g' \
		${SCRIPTS_DIR}/rabbitmq-server ${SCRIPTS_DIR}/rabbitmqctl ${SCRIPTS_DIR}/rabbitmq-env
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
