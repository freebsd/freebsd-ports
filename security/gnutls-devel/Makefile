# New ports collection makefile for:	gnutls
# Date created:		13 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://gd.tuwien.ac.at/privacy/gnupg/alpha/gnutls/ \
	http://www.mirrors.wiretapped.net/security/network-security/gnutls/ \
	ftp://ftp.gnupg.org/pub/gcrypt/alpha/gnutls/ \
	ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/ \
	ftp://ftp.gnutls.org/pub/gnutls/

MAINTAINER=	sergei@kolobov.com

LIB_DEPENDS=	gcrypt.6:${PORTSDIR}/security/libgcrypt \
		tasn1.0:${PORTSDIR}/security/libtasn1

.if defined(WITH_OPENCDK)
LIB_DEPENDS+=	opencdk.5:${PORTSDIR}/security/opencdk
.endif

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCS=		AUTHORS NEWS README THANKS

pre-configure:
	@${ECHO_MSG} ""
.if defined (WITH_OPENCDK)
	@${ECHO_MSG} "Enabled OpenCDK support"
.else
	@${ECHO_MSG} "OpenCDK support is disabled by default"
	@${ECHO_MSG} "Use WITH_OPENCDK=yes to enable"
.endif
	@${ECHO_MSG} ""

post-install:
	${RM} -f ${PREFIX}/lib/libgnutls.la ${PREFIX}/lib/libgnutls-extra.la
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
