# Created by: Loic Pefferkorn <loic-freebsd@loicp.eu>
# $FreeBSD$

PORTNAME=	amqp-utils
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	loic-freebsd@loicp.eu
COMMENT=	Command line utilies for interacting with AMQP compliant queues

LICENSE=	MIT

RUN_DEPENDS=	rubygem-amqp>=0.7.1:${PORTSDIR}/net/rubygem-amqp \
		rubygem-clio>=0.3.0:${PORTSDIR}/devel/rubygem-clio \
		rubygem-facets>=2.9:${PORTSDIR}/devel/rubygem-facets \
		rubygem-heredoc_unindent>=1.1.2:${PORTSDIR}/textproc/rubygem-heredoc_unindent \
		rubygem-json>=1.5:${PORTSDIR}/devel/rubygem-json \
		rubygem-msgpack>=0.4.5:${PORTSDIR}/devel/rubygem-msgpack \
		rubygem-trollop1>=1.16.2:${PORTSDIR}/devel/rubygem-trollop1

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES+=	bin/amqp-deleteq bin/amqp-dequeue bin/amqp-enqueue bin/amqp-peek bin/amqp-pop \
		bin/amqp-purge bin/amqp-spy bin/amqp-statq bin/amqp-unbind \
		bin/amqp-delexch bin/amqp-exchange

.include <bsd.port.mk>
