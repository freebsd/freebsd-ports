# $FreeBSD$

PORTNAME=	shishi
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Free implementation of the Kerberos 5 network security system

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgnutls.so:${PORTSDIR}/security/gnutls

USE_AUTOTOOLS=	libtool
USE_PERL5=	build
USES=		pathfix pkgconfig iconv perl5
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--with-db-dir=/var/shishi
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

INFO=		shishi

SUB_FILES=	pkg-message

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS=	LD_LIBRARY_PATH="${STAGEDIR}${PREFIX}/lib:${LOCALBASE}/lib:/usr/lib"

post-extract:
	@${RM} -f ${WRKSRC}/doc/shishi.info*
	@cd ${WRKSRC}/db/gl && ${LN} -s ../../build-aux/link-warning.h

post-patch:
	@${REINPLACE_CMD} -e 's/$$(LINK_WARNING_H)/link-warning.h/' \
		${WRKSRC}/db/gl/Makefile.in
	@${REINPLACE_CMD} -e 's:\.\./gl/libgnu.la:../db/gl/libgnu.la &:' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/^AM_CPPFLAGS/s:-I[^ ]*/gl ::g' \
		${WRKSRC}/examples/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libshishi.so \
		${STAGEDIR}${PREFIX}/lib/libshisa.so \
		${STAGEDIR}${PREFIX}/lib/security/pam_shishi.so

.include <bsd.port.mk>
