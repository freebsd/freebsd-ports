# New ports collection makefile for:   isync
# Date created:		2000-12-23
# Whom:			eivind
#
# $FreeBSD$

PORTNAME=	isync
PORTVERSION=	0.9.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Maintain local copies of remote IMAP folders w/synchronized flags

USE_GETOPT_LONG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		isync.1
PLIST_FILES=	bin/isync

CPPFLAGS=	-I${LOCALBASE}/include/db3 -I${OPENSSLINC}
LDFLAGS=	-L${LOCALBASE}/lib -ldb3 -L${OPENSSLLIB} -lssl -lcrypto

.include <bsd.port.mk>
