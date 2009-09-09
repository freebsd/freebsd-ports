# Ports collection makefile for:  pear-Mail_Queue
# Date created:			  05 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Mail_Queue
PORTVERSION=	1.2.3
CATEGORIES=	mail www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for put mails in queue and send them later in background

BUILD_DEPENDS=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail \
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime
RUN_DEPENDS=	${BUILD_DEPENDS}

#CATEGORY=	Mail
FILES=		Mail/Queue.php Mail/Queue/Body.php \
		Mail/Queue/Container.php Mail/Queue/Error.php \
		Mail/Queue/Container/creole.php Mail/Queue/Container/db.php \
		Mail/Queue/Container/mdb.php Mail/Queue/Container/mdb2.php
DOCS=		README TODO add_example.php base.php \
		mdb_mail_queue_schema.xml mysql.sql pgsql.sql send_example.php

OPTIONS=	PEAR_DB "PEAR::DB support" off \
		PEAR_MDB "PEAR::MDB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_DB)
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_MDB)
RUN_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if defined(WITH_PEAR_MDB2)
RUN_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
