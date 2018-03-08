# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Mail_Queue
PORTVERSION=	1.2.7
PORTREVISION=	1
CATEGORIES=	mail www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PEAR class for put mails in queue and send them later in background

BUILD_DEPENDS=	${PEARDIR}/Mail.php:mail/pear-Mail@${PHP_FLAVOR} \
		${PEARDIR}/Mail/mime.php:mail/pear-Mail_Mime@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Mail.php:mail/pear-Mail@${PHP_FLAVOR} \
		${PEARDIR}/Mail/mime.php:mail/pear-Mail_Mime@${PHP_FLAVOR}

USES=		pear

OPTIONS_DEFINE=	PEAR_DB PEAR_MDB PEAR_MDB2
PEAR_DB_DESC=	PEAR::DB support
PEAR_MDB_DESC=	PEAR::MDB support
PEAR_MDB2_DESC=	PEAR::MDB2 support

PEAR_DB_RUN_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB@${PHP_FLAVOR}
PEAR_MDB_RUN_DEPENDS=	${PEARDIR}/MDB.php:databases/pear-MDB@${PHP_FLAVOR}
PEAR_MDB2_RUN_DEPENDS=	${PEARDIR}/MDB2.php:databases/pear-MDB2@${PHP_FLAVOR}

.include <bsd.port.mk>
