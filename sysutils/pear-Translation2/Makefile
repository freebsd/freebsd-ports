# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Translation2
DISTVERSION=	2.0.4
PORTEPOCH=	1
CATEGORIES=	sysutils devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for multilingual applications management

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	yes
PEAR_AUTOINSTALL=	yes

LATEST_LINK=	pear-Translation2
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_CACHE_LITE}
RUN_DEPENDS+=	${PEARDIR}/Cache/Lite.php:${PORTSDIR}/sysutils/pear-Cache_Lite
.endif

.if ${PORT_OPTIONS:MPEAR_DB}
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if ${PORT_OPTIONS:MPEAR_DB_DATAOBJECT}
RUN_DEPENDS+=	${PEARDIR}/DB/DataObject.php:${PORTSDIR}/databases/pear-DB_DataObject
.endif

.if ${PORT_OPTIONS:MPEAR_MDB}
RUN_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if ${PORT_OPTIONS:MPEAR_MDB2}
RUN_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if ${PORT_OPTIONS:MPEAR_FILE_GETTEXT}
RUN_DEPENDS+=	${PEARDIR}/File/Gettext.php:${PORTSDIR}/sysutils/pear-File_Gettext
.endif

.if ${PORT_OPTIONS:MPEAR_I18NV2}
RUN_DEPENDS+=	${PEARDIR}/File/I18Nv2.php:${PORTSDIR}/sysutils/pear-I18Nv2
.endif

.if ${PORT_OPTIONS:MPEAR_XML_SERIALIZER}
RUN_DEPENDS+=	${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
