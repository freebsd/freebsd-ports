# Ports collection makefile for:  pear-Auth
# Date created:			  2 February 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Auth
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	security pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for creating an authentication system

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-Auth
OPTIONS=	PEAR_LOG "PEAR::Log support" off \
		PEAR_FILE_PASSWD "PEAR::File_Passwd support" off \
		PEAR_NET_POP3 "PEAR::Net_POP3 support" off \
		PEAR_DB "PEAR::DB support" off \
		PEAR_MDB "PEAR::MDB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off \
		PEAR_AUTH_RADIUS "PEAR::AUTH_RADIUS support" off \
		PEAR_CRYPT_CHAP "PEAR::CRYPT_CHAP support" off \
		PEAR_FILE_SMBPASSWD "PEAR::File_SMBPasswd support" off \
		PEAR_SOAP "PEAR::SOAP support" off \
		PEAR_NET_VPOPMAILD "PEAR::Net_Vpopmaild support" off

FILES=		Auth.php Auth.php.bak Auth/Anonymous.php Auth/Auth.php \
		Auth/Controller.php Container.php Container/Array.php \
		Container/DB.php Container/DBLite.php Container/File.php \
		Container/IMAP.php Container/KADM5.php Container/LDAP.php \
		Container/MDB.php Container/MDB2.php Container/Multiple.php \
		Container/PEAR.php Container/POP3.php Container/RADIUS.php \
		Container/SAP.php Container/SMBPasswd.php Container/SOAP.php \
		Container/SOAP5.php Container/vpopmail.php Frontend/Html.php \
		Frontend/md5.js
TESTS=		DBContainer.php FileContainer.php MDB2Container.php MDBContainer.php \
		POP3Container.php POP3aContainer.php TestAuthContainer.php \
		auth_container_db_options.php auth_container_file_options.php \
		auth_container_mdb2_options.php auth_container_mdb_options.php \
		auth_container_pop3_options.php auth_container_pop3a_options.php \
		bug8735.passwd bug8735.phpt mysql_test_db.sql tests.php users
EXAMPLES=	logging.php multi-container.php
DOCS=		README.AdvancedSecurity README.Auth
_DOCSDIR=	.

post-extract:
	@${REINPLACE_CMD} -e "s|@version@|${PORTVERSION}|" ${WRKSRC}/Auth.php

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_LOG)
RUN_DEPENDS+=	${PEARDIR}/Log/syslog.php:${PORTSDIR}/sysutils/pear-Log
.endif

.if defined(WITH_PEAR_FILE_PASSWD)
RUN_DEPENDS+=	${PEARDIR}/File/Passwd.php:${PORTSDIR}/security/pear-File_Passwd
.endif

.if defined(WITH_PEAR_CRYPT_CHAP)
RUN_DEPENDS+=	${PEARDIR}/Crypt/CHAP.php:${PORTSDIR}/security/pear-Crypt_CHAP
.endif

.if defined(WITH_PEAR_NET_POP3)
RUN_DEPENDS+=	${PEARDIR}/Net/POP3.php:${PORTSDIR}/net/pear-Net_POP3
.endif

.if defined(WITH_PEAR_DB)
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_MDB)
RUN_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if defined(WITH_PEAR_MDB2)
RUN_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PEAR_AUTH_RADIUS)
RUN_DEPENDS+=	${PEARDIR}/Auth/RADIUS.php:${PORTSDIR}/net/pear-Auth_RADIUS
.endif

.if defined(WITH_PEAR_FILE_SMBPASSWD)
RUN_DEPENDS+=	${PEARDIR}/File/SMBPasswd.php:${PORTSDIR}/security/pear-File_SMBPasswd
.endif

.if defined(WITH_PEAR_SOAP)
RUN_DEPENDS+=	${PEARDIR}/SOAP/Base.php:${PORTSDIR}/net/pear-SOAP
.endif

.if defined(WITH_PEAR_NET_VPOPMAILD)
RUN_DEPENDS+=	${PEARDIR}/Net/Vpopmaild.php:${PORTSDIR}/net/pear-Net_Vpopmaild
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
