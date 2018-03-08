# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Translation2
DISTVERSION=	2.0.4
PORTEPOCH=	1
CATEGORIES=	sysutils devel pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PEAR class for multilingual applications management

USES=		pear shebangfix
SHEBANG_FILES=	scripts/t2xmlchk.php
NO_ARCH=	yes

OPTIONS_DEFINE=	PEAR_CACHE_LITE PEAR_DB PEAR_DB_DATAOBJECT PEAR_MDB PEAR_MDB2 \
		PEAR_FILE_GETTEXT PEAR_I18NV2 PEAR_XML_SERIALIZER
PEAR_CACHE_LITE_DESC=	PEAR::Cache_Lite support
PEAR_DB_DESC=	PEAR::DB support
PEAR_DB_DATAOBJECT_DESC=	PEAR::DB_DataObject support
PEAR_MDB_DESC=	PEAR::MDB support
PEAR_MDB2_DESC=	PEAR::MDB2 support
PEAR_FILE_GETTEXT_DESC=	PEAR::File_Gettext support
PEAR_I18NV2_DESC=	PEAR::I18Nv2 support
PEAR_XML_SERIALIZER_DESC=	PEAR::XML_Serializer support

PEAR_CACHE_LITE_RUN_DEPENDS=	${PEARDIR}/Cache/Lite.php:sysutils/pear-Cache_Lite@${PHP_FLAVOR}
PEAR_DB_RUN_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB@${PHP_FLAVOR}
PEAR_DB_DATAOBJECT_RUN_DEPENDS=	${PEARDIR}/DB/DataObject.php:databases/pear-DB_DataObject@${PHP_FLAVOR}
PEAR_MDB_RUN_DEPENDS=	${PEARDIR}/MDB.php:databases/pear-MDB@${PHP_FLAVOR}
PEAR_MDB2_RUN_DEPENDS=	${PEARDIR}/MDB2.php:databases/pear-MDB2@${PHP_FLAVOR}
PEAR_FILE_GETTEXT_RUN_DEPENDS=	${PEARDIR}/File/Gettext.php:sysutils/pear-File_Gettext@${PHP_FLAVOR}
PEAR_I18NV2_RUN_DEPENDS=	${PEARDIR}/File/I18Nv2.php:sysutils/pear-I18Nv2@${PHP_FLAVOR}
PEAR_XML_SERIALIZER_RUN_DEPENDS=	${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer@${PHP_FLAVOR}

.include <bsd.port.mk>
