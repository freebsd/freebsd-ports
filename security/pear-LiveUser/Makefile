# Ports collection makefile for:  pear-LiveUser
# Date created:			  29 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	LiveUser
PORTVERSION=	0.14.0
CATEGORIES=	security www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR user authentication and permission management framework

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

LATEST_LINK=	pear-LiveUser
OPTIONS=	PEAR_DB "PEAR::DB support" on \
		PEAR_MDB "PEAR::MDB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off \
		PEAR_LOG "PEAR::Log support" off \
		PEAR_XML_TREE "PEAR::XML_Tree support" off \
		PEAR_CRYPT_RC4 "PEAR::Crypt_RC4 support" off

CATEGORY=	LiveUser
FILES=		Auth/Common.php Auth/DB.php Auth/MDB.php Auth/MDB2.php \
		Auth/PEARAuth.php Auth/XML.php Perm/Complex.php Perm/Medium.php \
		Perm/Simple.php Perm/Storage.php Perm/Storage/Cache.php \
		Perm/Storage/DB.php Perm/Storage/MDB.php Perm/Storage/MDB2.php \
		Perm/Storage/SQL.php Perm/Storage/XML.php LiveUser.php
SQLS=		Auth_DB.sql auth_mdb_schema.xml Auth_XML.xml perm_db.sql \
		perm_db_complex.sql perm_db_medium.sql perm_db_simple.sql \
		perm_mdb_schema.xml Perm_XML.xml README
DOCS=		lgpl.txt
EXAMPLES=	README example1/Auth_XML.xml example1/conf.php example1/example.php \
		example1/index.html example1/README example2/Auth_XML.xml \
		example2/conf.php example2/example.php example2/index.html \
		example2/Perm_XML.xml example2/README example4/Auth_XML.xml \
		example4/conf.php example4/demodata.sql example4/error-page.tpl.php \
		example4/finish.inc.php example4/functions.js example4/index.html \
		example4/loginform.tpl.php example4/news_change.php \
		example4/news_change.tpl.php example4/news_new.php \
		example4/news_new.tpl.php example4/news_notallowed.tpl.php \
		example4/news_view.php example4/news_view.tpl.php example4/style.css
_EXAMPLESDIR=	docs/examples
_DOCSDIR=	.

.include <bsd.port.pre.mk>

PHP_VERS=       ${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 420
IGNORE=         "You need PHP 4.2.0 or later to install PEAR::LiveUser"
.endif

.if !defined(WITHOUT_PEAR_DB)
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_MDB)
BUILD_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if defined(WITH_PEAR_MDB2)
BUILD_DEPENDS+= ${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PEAR_LOG)
BUILD_DEPENDS+=	 ${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
.endif

.if defined(WITH_PEAR_XML_TREE)
BUILD_DEPENDS+=	${PEARDIR}/XML/Tree.php:${PORTSDIR}/devel/pear-XML_Tree
.endif

.if defined(WITH_PEAR_CRYPT_RC4)
BUILD_DEPENDS+=	${PEARDIR}/Crypt/Rc4.php:${PORTSDIR}/security/pear-Crypt_RC4
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
