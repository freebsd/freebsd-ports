# New ports collection makefile for:	gnutls
# Date created:		13 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	1.0.13
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GNUPG} \
	http://www.mirrors.wiretapped.net/security/network-security/gnutls/ \
	ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/ \
	ftp://ftp.gnutls.org/pub/gnutls/
MASTER_SITE_SUBDIR=	alpha/gnutls

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

LIB_DEPENDS=	gcrypt.12:${PORTSDIR}/security/libgcrypt \
		gpg-error.1:${PORTSDIR}/security/libgpg-error \
		opencdk.8:${PORTSDIR}/security/opencdk \
		tasn1.2:${PORTSDIR}/security/libtasn1

CONFLICTS=	gnutls-devel-*

USE_GPG?=	yes
SIG_SUFFIX=	.sig.asc
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-included-lzo

MAN1=		certtool.1 gnutls-cli.1 gnutls-cli-debug.1 \
       		gnutls-serv.1 gnutls-srpcrypt.1
DOCS=		AUTHORS NEWS README THANKS doc/tex/*.ps
EXAMPLES=	doc/examples/*.c

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
