# New ports collection makefile for:	w3c-httpd
# Version required:	3.0A
# Date created:		29 October 1994
# Whom:			pst
#
# $Id: Makefile,v 1.18 1998/10/15 02:03:14 jseger Exp $
#

DISTNAME=	w3c-httpd-3.0A
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/httpd/ \
		ftp://ftp-eu.w3.org/pub/httpd/

MAINTAINER=	giffunip@asme.org

NO_WRKSUBDIR=	yes

BROKEN_ELF=	yes

WWW_ROOT=	${PREFIX}/www

pre-configure:
.if !defined(MD5_PW)
	@echo ""
	@echo "Defaulting to DES encrypted passwords."
	@echo "Set the environment variable MD5_PW if you want MD5 encrypted passwords."
	@echo ""
.else
	@echo "CFLAGS += -DMD5_PW" >> ${WRKDIR}/All/${OSNAME}/Makefile.include
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
