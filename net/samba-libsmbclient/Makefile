# New ports collection makefile for:	samba-libsmbclient
# Date created:				23 Juli 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	samba
PORTVERSION=	3.0.1
CATEGORIES=	net
MASTER_SITES=   http://us3.samba.org/samba/ftp/%SUBDIR%/ \
                http://us4.samba.org/samba/ftp/%SUBDIR%/ \
                http://us5.samba.org/samba/ftp/%SUBDIR%/
MASTER_SITE_SUBDIR=     . old-versions
PKGNAMESUFFIX=  -libsmbclient

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	The shared lib from the samba packages

USE_BZIP2=		yes
USE_SIZE=		yes
USE_AUTOCONF=		yes
WANT_AUTOCONF_VER=	253
INSTALLS_SHLIB=		yes

WRKSRC=		${WRKDIR}/${DISTNAME}/source

CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib

do-build:
	cd ${WRKSRC} && ${MAKE} include/proto.h
	cd ${WRKSRC} && ${MAKE} libsmbclient

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/include/libsmbclient.h ${PREFIX}/include
	${INSTALL_SCRIPT} ${WRKSRC}/bin/libsmbclient.so ${PREFIX}/lib/libsmbclient.so.0
	${LN} -s ${PREFIX}/lib/libsmbclient.so.0 ${PREFIX}/lib/libsmbclient.so

.include <bsd.port.mk>
