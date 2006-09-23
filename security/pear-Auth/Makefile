# Ports collection makefile for:  pear-Auth
# Date created:			  2 February 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Auth
PORTVERSION=	1.3.0
CATEGORIES=	security pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class for creating an authentication system

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-Auth
OPTIONS=	PEAR_FILE_PASSWD "PEAR::File_Passwd support" off \
		PEAR_NET_POP3 "PEAR::Net_POP3 support" off \
		PEAR_DB "PEAR::DB support" off \
		PEAR_MDB "PEAR::MDB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off \
		PEAR_FILE_SMBPASSWD "PEAR::File_SMBPasswd support" off

CATEGORY=	Auth
FILES=		Auth.php Auth/Auth.php Container.php Container/DB.php \
		Container/DBLite.php Container/File.php Container/IMAP.php \
		Container/POP3.php Container/LDAP.php Container/MDB.php \
		Container/MDB2.php Container/RADIUS.php Container/SMBPasswd.php \
		Container/SOAP.php Container/vpopmail.php
TESTS=		auth_container_db_options.php DBContainer.php \
		auth_container_file_options.php FileContainer.php \
		auth_container_pop3_options.php POP3Container.php \
		auth_container_mdb_options.php MDBContainer.php \
		auth_container_mdb2_options.php MDB2Container.php \
		POP3Container.php auth_container_pop3a_options.php \
		POP3aContainer.php TestAuthContainer.php users tests.php
DOCS=		README.Auth
_DOCSDIR=	.

post-extract:
	@${REINPLACE_CMD} -e "s|@version@|${PORTVERSION}|" ${WRKSRC}/Auth.php

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_FILE_PASSWD)
RUN_DEPENDS+=	${PEARDIR}/File/Passwd.php:${PORTSDIR}/security/pear-File_Passwd
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

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
