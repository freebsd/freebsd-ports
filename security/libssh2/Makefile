# New ports collection makefile for:	libssh2
# Date created:		2005-04-07
# Whom:			Alexander Leidinger <netchild@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libssh2
PORTVERSION=	0.13
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library implementing the SSH2 protocol

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

PLIST_FILES=	include/libssh2.h \
		include/libssh2_publickey.h \
		include/libssh2_sftp.h \
		lib/libssh2.so \
		lib/libssh2.so.0

post-patch:
	@${REINPLACE_CMD} -e '/ssh2_sample\.o/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|SHLIB_SUFFIX_NAME@ |SHLIB_SUFFIX_NAME@.0 |g' \
		${WRKSRC}/src/Makefile.in

post-install:
	${LN} -s libssh2.so.0 ${PREFIX}/lib/libssh2.so

.include <bsd.port.mk>
