# Ports collection makefile for:  pear-LiveUser_Admin
# Date created:			  25 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	LiveUser_Admin
PORTVERSION=	0.1.0
CATEGORIES=	security www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR user authentication and permission management framework

BUILD_DEPENDS=	${PEARDIR}/LiveUser/LiveUser.php:${PORTSDIR}/security/pear-LiveUser
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

LATEST_LINK=	pear-LiveUser_Admin
OPTIONS=	PEAR_DB "PEAR::DB support" on \
		PEAR_MDB "PEAR::MDB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off \
		PEAR_LOG "PEAR::Log support" off \
		PEAR_XML_TREE "PEAR::XML_Tree support" off \
		PEAR_CRYPT_RC4 "PEAR::Crypt_RC4 support" off

CATEGORY=	LiveUser
FILES=		Admin/Auth/Common.php Admin/Auth/DB.php Admin/Auth/MDB.php \
		Admin/Auth/MDB2.php Admin/Perm/Complex.php Admin/Perm/Medium.php \
		Admin/Perm/Simple.php Admin/Perm/Storage/MDB2.php \
		Admin/Storage/MDB2.php Admin/Storage/SQL.php \
		Admin.php Admin/Storage.php
EXAMPLES=	Auth_XML.xml test.php example1/Application.php \
		example1/Area.php example1/config.inc.php \
		example1/create_db.sql example1/extra_sql.sql \
		example1/Group.php example1/GroupRights.php \
		example1/ImplyRights.php example1/index.php \
		example1/OutputRightsConstants.php example1/Rights.php \
		example1/Subgroups.php example1/User.php \
		example1/UserGroup.php example1/UserRights.php \
		example3/area51.php example3/coffeemaker.php example3/conf.php \
		example3/demodata.sql example3/example.php example3/index.html \
		example3/loginscreen.php example3/main.php example3/nav.php \
		example3/testarea.php
_EXAMPLESDIR=	docs/examples

post-extract:
	@${MKDIR} ${WRKSRC}/Admin
	@${MV} ${WRKSRC}/Auth ${WRKSRC}/Admin/
	@${MV} ${WRKSRC}/[P-S]* ${WRKSRC}/Admin/
	@${MV} ${WRKSRC}/docs/examples/example\ 1 ${WRKSRC}/docs/examples/example1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PEAR_DB)
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_MDB)
BUILD_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if defined(WITH_PEAR_MDB2)
BUILD_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PEAR_LOG)
BUILD_DEPENDS+=	${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
.endif

.if defined(WITH_PEAR_XML_TREE)
BUILD_DEPENDS+=	${PEARDIR}/XML/Tree.php:${PORTSDIR}/devel/pear-XML_Tree
.endif

.if defined(WITH_PEAR_CRYPT_RC4)
BUILD_DEPENDS+=	${PEARDIR}/Crypt/Rc4.php:${PORTSDIR}/security/pear-Crypt_RC4
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
