# Ports collection makefile for:  pear-LiveUser
# Date created:			  29 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	LiveUser
PORTVERSION=	0.16.14
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR user authentication and permission management framework

BUILD_DEPENDS=	${PEARDIR}/Event/Dispatcher.php:${PORTSDIR}/devel/pear-Event_Dispatcher
RUN_DEPENDS=	${PEARDIR}/Event/Dispatcher.php:${PORTSDIR}/devel/pear-Event_Dispatcher

PORTSCOUT=	skipv:0.61

LATEST_LINK=	pear-LiveUser
OPTIONS=	PEAR_DB "PEAR::DB support" off \
		PEAR_MDB "PEAR::MDB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off \
		PEAR_LOG "PEAR::Log support" off \
		PEAR_XML_TREE "PEAR::XML_Tree support" off \
		PEAR_CRYPT_RC4 "PEAR::Crypt_RC4 support" off

PEAR_AUTOINSTALL=yes

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_DB)
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_MDB)
RUN_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if defined(WITH_PEAR_MDB2)
RUN_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PEAR_LOG)
RUN_DEPENDS+=	 ${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log
.endif

.if defined(WITH_PEAR_XML_TREE)
RUN_DEPENDS+=	${PEARDIR}/XML/Tree.php:${PORTSDIR}/devel/pear-XML_Tree
.endif

.if defined(WITH_PEAR_CRYPT_RC4)
RUN_DEPENDS+=	${PEARDIR}/Crypt/Rc4.php:${PORTSDIR}/security/pear-Crypt_RC4
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
