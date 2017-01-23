# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Mail_Queue
PORTVERSION=	1.2.7
PORTREVISION=	1
CATEGORIES=	mail www pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR class for put mails in queue and send them later in background

BUILD_DEPENDS=	${PEARDIR}/Mail.php:mail/pear-Mail \
		${PEARDIR}/Mail/mime.php:mail/pear-Mail_Mime
RUN_DEPENDS=	${PEARDIR}/Mail.php:mail/pear-Mail \
		${PEARDIR}/Mail/mime.php:mail/pear-Mail_Mime

USES=	pear

OPTIONS_DEFINE=	PEAR_DB PEAR_MDB PEAR_MDB2
PEAR_DB_DESC=	PEAR::DB support
PEAR_MDB_DESC=	PEAR::MDB support
PEAR_MDB2_DESC=	PEAR::MDB2 support

PEAR_DB_RUN_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB
PEAR_MDB_RUN_DEPENDS=	${PEARDIR}/MDB.php:databases/pear-MDB
PEAR_MDB2_RUN_DEPENDS=	${PEARDIR}/MDB2.php:databases/pear-MDB2

.include <bsd.port.mk>
