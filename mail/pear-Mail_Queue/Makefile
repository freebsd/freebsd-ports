# Ports collection makefile for:  pear-Mail_Queue
# Date created:			  05 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Mail_Queue
PORTVERSION=	1.1.3
CATEGORIES=	mail www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class for put mails in queue and send them later in background

BUILD_DEPENDS=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Mail
FILES=		Queue.php Queue/Body.php Queue/Container.php	\
		Queue/Container/db.php Queue/Container/mdb.php	\
		Queue/Container/mdb2.php
DOCS=		add_example.php base.php mdb_mail_queue_schema.xml \
		mysql.sql pgsql.sql send_example.php TODO README

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
