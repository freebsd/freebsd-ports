# New ports collection makefile for:	opencdk
# Date created:		15 Jan 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	opencdk
PORTVERSION=	0.5.5
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG} \
		http://www.mirrors.wiretapped.net/security/network-security/gnutls/opencdk/ \
		ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/opencdk/ \
		ftp://ftp.gnutls.org/pub/gnutls/opencdk/
MASTER_SITE_SUBDIR=	alpha/gnutls/opencdk

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Open Crypto Development Kit

LIB_DEPENDS=	gcrypt.12:${PORTSDIR}/security/libgcrypt

USE_BZIP2=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-libgcrypt-prefix=${LOCALBASE}
USE_REINPLACE=	yes

DOCS=		AUTHORS NEWS README THANKS doc/opencdk-api.html

post-patch:
.for f in encrypt.c main.c misc.c
	${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' ${WRKSRC}/src/${f}
.endfor

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/*.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/*.gpg ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
