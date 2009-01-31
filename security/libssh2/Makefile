# New ports collection makefile for:	libssh2
# Date created:		2005-04-07
# Whom:			Alexander Leidinger <netchild@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libssh2
PORTVERSION=	0.2
PORTEPOCH=	1
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A library implementing the SSH2 protocol

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	include/libssh2.h \
		lib/libssh2.so.0

post-patch:
	@${REINPLACE_CMD} -e '/ssh2_sample\.o/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|SHLIB_SUFFIX_NAME@ |SHLIB_SUFFIX_NAME@.0 |g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
