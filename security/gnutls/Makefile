# New ports collection makefile for:	gnutls
# Date created:		13 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	1.0.24
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GNUPG} \
	http://www.mirrors.wiretapped.net/security/network-security/gnutls/ \
	ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/ \
	ftp://ftp.gnutls.org/pub/gnutls/
MASTER_SITE_SUBDIR=	alpha/gnutls

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

LIB_DEPENDS=	gcrypt.13:${PORTSDIR}/security/libgcrypt \
		gpg-error.1:${PORTSDIR}/security/libgpg-error

.if defined(WITH_OPENCDK) || exists(${LOCALBASE}/lib/libopencdk.so.8)
LIB_DEPENDS+=	opencdk.8:${PORTSDIR}/security/opencdk
.endif

.if defined(WITH_LIBTASN1) || exists(${LOCALBASE}/lib/libtasn1.so.2)
LIB_DEPENDS+=	tasn1.2:${PORTSDIR}/security/libtasn1
.endif

CONFLICTS=	gnutls-devel-[0-9]*

USE_GPG?=	yes
SIG_SUFFIX=	.sig
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GNOME=	pkgconfig
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-included-lzo

MAN1=		certtool.1 gnutls-cli.1 gnutls-cli-debug.1 \
       		gnutls-serv.1 srptool.1
DOCS=		AUTHORS NEWS README THANKS doc/tex/*.ps
EXAMPLES=	doc/examples/*.c

post-patch:
	@${REINPLACE_CMD} -e 's,(libdir)/pkgconfig,(prefix)/libdata/pkgconfig,' \
		${WRKSRC}/lib/Makefile.in ${WRKSRC}/libextra/Makefile.in

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
