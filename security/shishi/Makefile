# ex:ts=8
# Ports collection makefile for:	shishi
# Date created:			Oct 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	shishi
PORTVERSION=	0.0.8
CATEGORIES=	security
MASTER_SITES=	http://josefsson.org/${PORTNAME}/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free implementation of the Kerberos 5 network security system

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		intl.5:${PORTSDIR}/devel/gettext \
		idn.12:${PORTSDIR}/devel/libidn \
		gcrypt.6:${PORTSDIR}/security/libgcrypt \
		tasn1.2:${PORTSDIR}/security/libtasn1 \
		gnutls.7:${PORTSDIR}/security/gnutls

USE_GNOME=	gnomehack
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"
INSTALLS_SHLIB=	yes

INFO=	shishi
MAN1=	shishi.1

post-extract:
	@${RM} -f ${WRKSRC}/doc/shishi.info*

post-install:
	@(cd ${WRKSRC}/doc/man ; \
		${LS} *.3 | ${SED} 's,^,man/man3/,' >> ${TMPPLIST})

.include <bsd.port.mk>
