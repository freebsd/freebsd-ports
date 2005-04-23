# New ports collection makefile for:	libssh2
# Date created:		2005-04-07
# Whom:			Alexander Leidinger <netchild@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libssh2
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	a library implementing the SSH2 protocol

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

PLIST_FILES=	include/libssh2.h \
		include/libssh2_sftp.h \
		lib/libssh2.so \
		lib/libssh2.so.0

post-patch:
	@${REINPLACE_CMD} -e 's:-lcrypto:-lcrypto -lm:g' ${WRKSRC}/configure

post-install:
	${MV} ${PREFIX}/lib/libssh2.so ${PREFIX}/lib/libssh2.so.0
	cd ${PREFIX}/lib; ${LN} -s libssh2.so.0 libssh2.so

.include <bsd.port.mk>
