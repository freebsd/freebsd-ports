# New ports collection makefile for:	gnutls
# Date created:		13 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	0.8.6
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GNUPG} \
	http://www.mirrors.wiretapped.net/security/network-security/gnutls/ \
	ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/ \
	ftp://ftp.gnutls.org/pub/gnutls/
MASTER_SITE_SUBDIR=	alpha/gnutls

MAINTAINER=	sergei@kolobov.com
COMMENT=	GNU Transport Layer Security library

LIB_DEPENDS=	gcrypt.6:${PORTSDIR}/security/libgcrypt \
		tasn1.2:${PORTSDIR}/security/libtasn1 \
		opencdk.6:${PORTSDIR}/security/opencdk

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCS=		AUTHORS NEWS README THANKS

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/*.c ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/tex/*.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
