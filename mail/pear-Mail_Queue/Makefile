# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Mail_Queue
PORTVERSION=	1.2.7
CATEGORIES=	mail www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for put mails in queue and send them later in background

BUILD_DEPENDS=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail \
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime
RUN_DEPENDS=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail \
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime

PEAR_AUTOINSTALL=	yes

OPTIONS_DEFINE=	PEAR_DB PEAR_MDB PEAR_MDB2
PEAR_DB_DESC=	PEAR::DB support
PEAR_MDB_DESC=	PEAR::MDB support
PEAR_MDB2_DESC=	PEAR::MDB2 support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_DB}
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if ${PORT_OPTIONS:MPEAR_MDB}
RUN_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if ${PORT_OPTIONS:MPEAR_MDB2}
RUN_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
