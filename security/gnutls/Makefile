# New ports collection makefile for:	gnutls
# Date created:		13 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	0.8.10
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GNUPG} \
	http://www.mirrors.wiretapped.net/security/network-security/gnutls/ \
	ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/ \
	ftp://ftp.gnutls.org/pub/gnutls/
MASTER_SITE_SUBDIR=	alpha/gnutls

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

LIB_DEPENDS=	gcrypt.6:${PORTSDIR}/security/libgcrypt

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-included-lzo

.if defined(WITH_LIBTASN1) || exists(${LOCALBASE}/lib/libtasn1.so.2)
LIB_DEPENDS+=		tasn1.2:${PORTSDIR}/security/libtasn1
.else
CONFIGURE_ARGS+=	--with-included-libtasn1
.endif

.if defined(WITH_OPENCDK) || exists(${LOCALBASE}/lib/libopencdk.so.6)
LIB_DEPENDS+=		opencdk.6:${PORTSDIR}/security/opencdk
.else
CONFIGURE_ARGS+=	--disable-openpgp-authentication
.endif

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
