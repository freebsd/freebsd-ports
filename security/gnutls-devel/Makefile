# New ports collection makefile for:	gnutls-devel
# Date created:		2003-07-17
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	1.1.9
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GNUPG} \
	http://www.mirrors.wiretapped.net/security/network-security/gnutls/devel/ \
	ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/devel/ \
	ftp://ftp.gnutls.org/pub/gnutls/devel/
MASTER_SITE_SUBDIR=	alpha/gnutls/devel
PKGNAMESUFFIX=	-devel

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	GNU Transport Layer Security library (development version)

LIB_DEPENDS=	gcrypt.13:${PORTSDIR}/security/libgcrypt \
		gpg-error.1:${PORTSDIR}/security/libgpg-error \
		tasn1.2:${PORTSDIR}/security/libtasn1 \
		opencdk.8:${PORTSDIR}/security/opencdk

CONFLICTS=	gnutls-[0-9]*

USE_ICONV=	yes
USE_GETTEXT=	yes
USE_INC_LIBTOOL_VER=15
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
