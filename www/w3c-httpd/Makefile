# New ports collection makefile for:	w3c-httpd
# Date created:		29 October 1994
# Whom:			pst (orig)
#
# $FreeBSD$
#

PORTNAME=	w3c-httpd
PORTVERSION=	3.0A
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/httpd/ \
		ftp://ftp-eu.w3.org/pub/httpd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WWW server from the W3 Consortium (W3C)

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/wais:build

NO_WRKSUBDIR=	yes
WWW_ROOT?=	${PREFIX}/www
MAKE_ENV+=	PORTSDIR=${PORTSDIR}

pre-configure:
.if !defined(MD5_PW)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Defaulting to DES encrypted passwords."
	@${ECHO_MSG} "Set the environment variable MD5_PW if you want MD5 encrypted passwords."
	@${ECHO_MSG} ""
.else
	@${ECHO_CMD} "CFLAGS += -DMD5_PW" >> ${WRKDIR}/All/${OSNAME}/Makefile.include
.endif

do-install:
	${MKDIR} ${WWW_ROOT}/data ${WWW_ROOT}/cgi-bin ${WWW_ROOT}/htbin
	${CP} -R ${WRKSRC}/server_root/icons $(WWW_ROOT)
	${CP} ${WRKSRC}/server_root/config/*.conf $(PREFIX)/etc
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/httpd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/htadm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/htimage ${WWW_ROOT}/htbin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/cgiparse ${WWW_ROOT}/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/cgiutils ${WWW_ROOT}/cgi-bin

.include <bsd.port.mk>

.if (${OPSYS} == "FreeBSD")
OSNAME=	freebsd
.else
#	covers OpenBSD too
OSNAME=	netbsd
.endif
