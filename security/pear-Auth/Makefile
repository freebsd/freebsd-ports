# Ports collection makefile for:  pear-Auth
# Date created:			  2 February 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Auth
PORTVERSION=	1.2.3
CATEGORIES=	security www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR authentication methods

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Auth
FILES=		Auth.php Container.php Container/DB.php Container/File.php \
		Container/IMAP.php Container/LDAP.php Container/MDB.php \
		Container/POP3.php Container/RADIUS.php Container/SMBPasswd.php \
		Container/SOAP.php Container/vpopmail.php
TESTS=		DBContainer.php FileContainer.php POP3Container.php \
		POP3aContainer.php TestAuthContainer.php \
		auth_container_db_options.php auth_container_file_options.php \
		auth_container_pop3_options.php auth_container_pop3a_options.php \
		tests.php users

do-install-tests-msg: .USE
	@${ECHO_MSG} "     (These tests require PHPUnit - see"
	@${ECHO_MSG} "     <http://pear.php.net/package/PHPUnit/>;)."

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

.if exists(${PEARDIR}/DB.php)
WITH_DB=	yes
.endif

.if defined(WITH_DB)
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.include <bsd.port.post.mk>
