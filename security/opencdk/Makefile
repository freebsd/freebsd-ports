# New ports collection makefile for:	opencdk
# Date created:		15 Jan 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	opencdk
PORTVERSION=	0.4.1
CATEGORIES=	security
MASTER_SITES=	http://gd.tuwien.ac.at/privacy/gnupg/alpha/gnutls/opencdk/ \
		ftp://ftp.gnutls.org/pub/gnutls/opencdk/ \
		ftp://ftp.gnupg.org/pub/gcrypt/alpha/gnutls/opencdk/ \
		http://www.mirrors.wiretapped.net/security/network-security/gnutls/opencdk/ \
		ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/opencdk/

MAINTAINER=	sergei@kolobov.com

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		gcrypt.6:${PORTSDIR}/security/libgcrypt

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lgnugetopt"

DOCS=		AUTHORS NEWS README THANKS

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/*.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/*.gpg ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/opencdk-api.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
