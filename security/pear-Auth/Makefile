# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	Auth
PORTVERSION=	1.6.4
CATEGORIES=	security pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for creating an authentication system

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

PEAR_AUTOINSTALL=	yes
LATEST_LINK=	pear-Auth
OPTIONS_DEFINE=	PEAR_LOG PEAR_FILE_PASSWD PEAR_NET_POP3 PEAR_DB PEAR_MDB \
		PEAR_MDB2 PEAR_AUTH_RADIUS PEAR_CRYPT_CHAP PEAR_FILE_SMBPASSWD \
		PEAR_SOAP PEAR_NET_VPOPMAILD
PEAR_LOG_DESC=	PEAR::Log support
PEAR_FILE_PASSWD_DESC=	PEAR::File_Passwd support
PEAR_NET_POP3_DESC=	PEAR::Net_POP3 support
PEAR_DB_DESC=	PEAR::DB support
PEAR_MDB_DESC=	PEAR::MDB support
PEAR_MDB2_DESC=	PEAR::MDB2 support
PEAR_AUTH_RADIUS_DESC=	PEAR::AUTH_RADIUS support
PEAR_CRYPT_CHAP_DESC=	PEAR::CRYPT_CHAP support
PEAR_FILE_SMBPASSWD_DESC=	PEAR::File_SMBPasswd support
PEAR_SOAP_DESC=	PEAR::SOAP support
PEAR_NET_VPOPMAILD_DESC=	PEAR::Net_Vpopmaild support

post-extract:
	@${REINPLACE_CMD} -e "s|@version@|${PORTVERSION}|" ${WRKSRC}/Auth.php

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_LOG}
RUN_DEPENDS+=	${PEARDIR}/Log/syslog.php:${PORTSDIR}/sysutils/pear-Log
.endif

.if ${PORT_OPTIONS:MPEAR_FILE_PASSWD}
RUN_DEPENDS+=	${PEARDIR}/File/Passwd.php:${PORTSDIR}/security/pear-File_Passwd
.endif

.if ${PORT_OPTIONS:MPEAR_CRYPT_CHAP}
RUN_DEPENDS+=	${PEARDIR}/Crypt/CHAP.php:${PORTSDIR}/security/pear-Crypt_CHAP
.endif

.if ${PORT_OPTIONS:MPEAR_NET_POP3}
RUN_DEPENDS+=	${PEARDIR}/Net/POP3.php:${PORTSDIR}/net/pear-Net_POP3
.endif

.if ${PORT_OPTIONS:MPEAR_DB}
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if ${PORT_OPTIONS:MPEAR_MDB}
RUN_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if ${PORT_OPTIONS:MPEAR_MDB2}
RUN_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if ${PORT_OPTIONS:MPEAR_AUTH_RADIUS}
RUN_DEPENDS+=	${PEARDIR}/Auth/RADIUS.php:${PORTSDIR}/net/pear-Auth_RADIUS
.endif

.if ${PORT_OPTIONS:MPEAR_FILE_SMBPASSWD}
RUN_DEPENDS+=	${PEARDIR}/File/SMBPasswd.php:${PORTSDIR}/security/pear-File_SMBPasswd
.endif

.if ${PORT_OPTIONS:MPEAR_SOAP}
RUN_DEPENDS+=	${PEARDIR}/SOAP/Base.php:${PORTSDIR}/net/pear-SOAP
.endif

.if ${PORT_OPTIONS:MPEAR_NET_VPOPMAILD}
RUN_DEPENDS+=	${PEARDIR}/Net/Vpopmaild.php:${PORTSDIR}/net/pear-Net_Vpopmaild
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
