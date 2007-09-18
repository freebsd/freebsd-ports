# Ports collection makefile for:  pear-Mail_Queue
# Date created:			  05 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Mail_Queue
PORTVERSION=	1.2.1
CATEGORIES=	mail www pear

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	PEAR class for put mails in queue and send them later in background

BUILD_DEPENDS=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail \
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Mail
FILES=		Queue.php Queue/Body.php Queue/Container.php \
		Queue/Container/creole.php Queue/Container/db.php \
		Queue/Container/mdb.php	Queue/Container/mdb2.php
DOCS=		README TODO add_example.php base.php \
		mdb_mail_queue_schema.xml mysql.sql pgsql.sql send_example.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
