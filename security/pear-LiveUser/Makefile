# Ports collection makefile for:  pear-LiveUser
# Date created:			  29 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	LiveUser
PORTVERSION=	0.13.3
CATEGORIES=	security www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR user authentication and permission management framework

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR \
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-LiveUser
OPTIONS=	PEAR_DB "PEAR::DB support" on \
		PEAR_MDB "PEAR::MDB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off \
		PEAR_XML_TREE "PEAR::XML_Tree support" off \
		PEAR_CRYPT_RC4 "PEAR::Crypt_RC4 support" off

CATEGORY=	LiveUser
FILES=		Admin.php Admin/Admin.php Admin/Auth/Common.php Admin/Auth/Container/DB.php \
		Admin/Auth/Container/MDB.php Admin/Auth/Container/MDB2.php \
		Admin/Perm/Common.php Admin/Perm/Container/DB_Complex.php \
		Admin/Perm/Container/DB_Medium.php Admin/Perm/Container/DB_Simple.php \
		Admin/Perm/Container/MDB2_Complex.php Admin/Perm/Container/MDB2_Medium.php \
		Admin/Perm/Container/MDB2_Simple.php Admin/Perm/Container/MDB_Complex.php \
		Admin/Perm/Container/MDB_Medium.php Admin/Perm/Container/MDB_Simple.php \
		Auth/Common.php Auth/Container/DB.php Auth/Container/MDB.php \
		Auth/Container/MDB2.php Auth/Container/PEAR_Auth.php Auth/Container/XML.php \
		Perm/Common.php Perm/Container/DB/Complex.php Perm/Container/DB/Medium.php \
		Perm/Container/Admin.php Perm/Container/DB/Simple.php \
		Perm/Container/MDB/Complex.php 	Perm/Container/MDB/Medium.php \
		Perm/Container/MDB/Simple.php Perm/Container/MDB2/Complex.php \
		Perm/Container/MDB2/Medium.php Perm/Container/MDB2/Simple.php \
		Perm/Container/XML/Simple.php LiveUser.php
SQLS=		perm_db_complex.sql perm_db_medium.sql perm_db_simple.sql README
DOCS=		docs/dia_admin_diagram.xml docs/dia_diagram.xml docs/Perm_DB_Complex.png \
		docs/Perm_DB_Simple.png lgpl.txt
EXAMPLES=	README admin_example/create_db.sql admin_example/README \
		admin_example/DB/admin_example.php admin_example/DB/config.inc.php \
		admin_example/MDB/admin_example_mdb.php admin_example/MDB/config_mdb.inc.php \
		admin_example/MDB2/admin_example_mdb2.php admin_example/MDB2/config_mdb2.inc.php \
		example1/Auth_XML.xml example1/conf.php example1/example.php example1/index.html \
		example1/README example2/Auth_XML.xml example2/conf.php example2/example.php \
		example2/index.html example2/Perm_XML.xml example2/README example3/area51.php \
		example3/coffeemaker.php example3/conf.php example3/demodata.sql \
		example3/example.php example3/index.html example3/loginscreen.php \
		example3/main.php example3/nav.php example3/testarea.php example4/conf.php \
		example4/demodata.sql example4/error-page.tpl.php example4/finish.inc.php \
		example4/functions.js example4/index.html example4/loginform.tpl.php \
		example4/news_change.php example4/news_change.tpl.php example4/news_new.php \
		example4/news_new.tpl.php example4/news_notallowed.tpl.php example4/news_view.php \
		example4/news_view.tpl.php example4/style.css example5/admin.php example5/admin.tpl \
		example5/admin_example.php example5/conf.php example5/create_db.sql \
		example5/home.php example5/home.tpl example5/index.php example5/layout_frontend.css \
		example5/liveuser_rights.php example5/login_form.tpl example5/news.tpl \
		example5/news_edit.tpl example5/news_list.tpl example5/README
_EXAMPLESDIR=	docs/examples
_DOCSDIR=	.

post-extract:
	@${CP} ${WRKSRC}/Admin/Admin.php ${WRKSRC}
	@${CP} ${WRKSRC}/Admin.php ${WRKSRC}/Perm/Container

	@${MKDIR} ${WRKSRC}/misc/schema
	@${MV} ${WRKSRC}/sql/Auth_DB.sql ${WRKSRC}/misc/schema/Auth_DB.sql
	@${MV} ${WRKSRC}/sql/auth_mdb_schema.xml ${WRKSRC}/misc/schema/auth_mdb_schema.xml
	@${MV} ${WRKSRC}/sql/Auth_XML.xml ${WRKSRC}/misc/schema/Auth_XML.xml
	@${MV} ${WRKSRC}/sql/perm_db.sql ${WRKSRC}/misc/schema/perm_db.sql
	@${MV} ${WRKSRC}/sql/perm_mdb_schema.xml ${WRKSRC}/misc/schema/perm_mdb_schema.xml
	@${MV} ${WRKSRC}/sql/Perm_XML.xml ${WRKSRC}/misc/schema/Perm_XML.xml

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PEAR_DB)
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_MDB)
BUILD_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if defined(WITH_PEAR_MDB2)
BUILD_DEPENDS+= ${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PEAR_XML_TREE)
BUILD_DEPENDS+=	${PEARDIR}/XML/Tree.php:${PORTSDIR}/devel/pear-XML_Tree
.endif

.if defined(WITH_PEAR_CRYPT_RC4)
BUILD_DEPENDS+=	${PEARDIR}/Crypt/Rc4.php:${PORTSDIR}/security/pear-Crypt_RC4
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
