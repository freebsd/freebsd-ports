# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	LiveUser_Admin
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR user authentication and permission management framework

BUILD_DEPENDS=	${PEARDIR}/LiveUser.php:${PORTSDIR}/security/pear-LiveUser
RUN_DEPENDS=	${PEARDIR}/LiveUser.php:${PORTSDIR}/security/pear-LiveUser

OPTIONS_DEFINE=	PEAR_DB PEAR_MDB PEAR_MDB2 PEAR_LOG PEAR_XML_TREE PEAR_CRYPT_RC4

PEAR_DB_DESC=	PEAR::DB support
PEAR_MDB_DESC=	PEAR::MDB support
PEAR_MDB2_DESC=	PEAR::MDB2 support
PEAR_LOG_DESC=	PEAR::Log support
PEAR_XML_TREE_DESC=	PEAR::XML_Tree support
PEAR_CRYPT_RC4_DESC=	PEAR::Crypt_RC4 support

USES=	pear

PEAR_DB_RUN_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
PEAR_MDB_RUN_DEPENDS=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
PEAR_MDB2_RUN_DEPENDS=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
PEAR_LOG_RUN_DEPENDS=	${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
PEAR_XML_TREE_RUN_DEPENDS=	${PEARDIR}/XML/Tree.php:${PORTSDIR}/devel/pear-XML_Tree
PEAR_CRYPT_RC4_RUN_DEPENDS=	${PEARDIR}/Crypt/Rc4.php:${PORTSDIR}/security/pear-Crypt_RC4

.include <bsd.port.mk>
