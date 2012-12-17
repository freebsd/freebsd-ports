# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Translation2
DISTVERSION=	2.0.4
PORTEPOCH=	1
CATEGORIES=	sysutils devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for multilingual applications management

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PHP=	yes
PEAR_CATSRC=	yes

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

FILES=		Translation2.php Translation2/Admin.php Translation2/Container.php \
		Translation2/Decorator.php Translation2/Admin/Decorator.php \
		Translation2/Admin/Container/dataobjectsimple.php \
		Translation2/Admin/Container/db.php \
		Translation2/Admin/Container/gettext.php \
		Translation2/Admin/Container/mdb.php \
		Translation2/Admin/Container/mdb2.php \
		Translation2/Admin/Container/xml.php \
		Translation2/Admin/Decorator/Autoadd.php \
		Translation2/Container/dataobjectsimple.php \
		Translation2/Container/db.php Translation2/Container/gettext.php \
		Translation2/Container/mdb.php Translation2/Container/mdb2.php \
		Translation2/Container/xml.php \
		Translation2/Decorator/CacheLiteFunction.php \
		Translation2/Decorator/CacheMemory.php \
		Translation2/Decorator/DefaultText.php \
		Translation2/Decorator/ErrorText.php Translation2/Decorator/Iconv.php \
		Translation2/Decorator/Lang.php Translation2/Decorator/SpecialChars.php \
		Translation2/Decorator/UTF8.php
DOCS=		gettext_readme.txt
TESTS=		admin_containers_tests.php admin_db_test.php admin_gettext_po_test.php \
		admin_mdb2_test.php admin_mdb_test.php admin_xml_test.php all_tests.php \
		containers_tests.php db_test.php db_test_base.php \
		dbms.php gettext_domains.ini \
		gettext_langs.ini gettext_mo_test.php gettext_po_test.php \
		gettext_prepare.php i18n.xml mdb2_test.php mdb_test.php readme.txt \
		simple_include.php tests.sql translation2_admin_include.php \
		translation2_include.php xml_test.php
EXAMPLES=	gettext_admin.php gettext_domains.ini gettext_langs.ini \
		gettext_prepare.php gettext_settings.php settings.php \
		settings_multitable.php \
		Translation2_example.php Translation2_example.sql \
		Translation2_gettext_example.php Translation2_example_multitable.sql
_EXAMPLESDIR=	docs/examples

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
