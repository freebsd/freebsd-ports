# New ports collection makefile for:	samba-libsmbclient
# Date created:				23 Juli 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	samba
PORTVERSION=	3.0.2a
CATEGORIES=	net
MASTER_SITES=	http://us3.samba.org/samba/ftp/%SUBDIR%/ \
		http://us1.samba.org/samba/ftp/%SUBDIR%/ \
		http://us4.samba.org/samba/ftp/%SUBDIR%/ \
		http://us5.samba.org/samba/ftp/%SUBDIR%/ \
		ftp://ca.samba.org/%SUBDIR%/ \
		ftp://de.samba.org/samba.org/%SUBDIR%/ \
		ftp://ftp.k2.net/mirrors/samba/%SUBDIR%/ \
		ftp://ftp.oss.eznetsols.org/samba/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/infosys/servers/samba/%SUBDIR%/ \
		ftp://giswitch.sggw.waw.pl/pub/unix/samba/%SUBDIR%/ \
		ftp://ru.samba.org/pub/samba/%SUBDIR%/ \
		ftp://tr.samba.org/samba/%SUBDIR%/ \
		http://sambafr.idealx.org/samba/ftp/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old-versions
PKGNAMESUFFIX=	-libsmbclient

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	The shared lib from the samba packages

USE_BZIP2=		yes
USE_SIZE=		yes
GNU_CONFIGURE=		yes
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
