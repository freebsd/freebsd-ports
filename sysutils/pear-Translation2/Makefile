# Ports collection makefile for:  pear-Translation2
# Date created:			  20 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Translation2
DISTVERSION=	2.0.0beta6
PORTEPOCH=	1
CATEGORIES=	sysutils devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class for multilingual applications management

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

LATEST_LINK=	pear-Translation2
OPTIONS=	PEAR_CACHE_LITE "PEAR::Cache_Lite support" off \
		PEAR_DB "PEAR::DB support" off \
		PEAR_DB_DATAOBJECT "PEAR::DB_DataObject support" off \
		PEAR_MDB "PEAR::MDB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off \
		PEAR_FILE_GETTEXT "PEAR::File_Gettext support" off \
		PEAR_I18NV2 "PEAR::I18Nv2 support" off \
		PEAR_XML_SERIALIZER "PEAR::XML_Serializer support" off

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
		containers_tests.php db_test.php dbms.php gettext_domains.ini \
		gettext_langs.ini gettext_mo_test.php gettext_po_test.php \
		gettext_prepare.php i18n.xml mdb2_test.php mdb_test.php readme.txt \
		simple_include.php tests.sql translation2_admin_include.php \
		translation2_include.php xml_test.php
EXAMPLES=	gettext_admin.php gettext_domains.ini gettext_langs.ini \
		gettext_prepare.php gettext_settings.php settings.php \
		Translation2_example.php Translation2_example.sql \
		Translation2_gettext_example.php
_EXAMPLESDIR=	docs/examples

post-extract:
	${MKDIR} ${WRKSRC}/Translation2
	${MV} ${WRKSRC}/[A-D]* ${WRKSRC}/Translation2

.if defined(WITH_PEAR_CACHE_LITE)
RUN_DEPENDS+=	${PEARDIR}/Cache/Lite.php:${PORTSDIR}/sysutils/pear-Cache_Lite
.endif

.if defined(WITH_PEAR_DB)
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_DB_DATAOBJECT)
RUN_DEPENDS+=	${PEARDIR}/DB/DataObject.php:${PORTSDIR}/databases/pear-DB_DataObject
.endif

.if defined(WITH_PEAR_MDB)
RUN_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if defined(WITH_PEAR_MDB2)
RUN_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PEAR_FILE_GETTEXT)
RUN_DEPENDS+=	${PEARDIR}/File/Gettext.php:${PORTSDIR}/sysutils/pear-File_Gettext
.endif

.if defined(WITH_PEAR_I18NV2)
RUN_DEPENDS+=	${PEARDIR}/File/I18Nv2.php:${PORTSDIR}/sysutils/pear-I18Nv2
.endif

.if defined(WITH_PEAR_XML_SERIALIZER)
RUN_DEPENDS+=	${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
