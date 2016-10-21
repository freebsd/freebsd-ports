# $FreeBSD$

PORTNAME=	shishi
PORTVERSION=	1.0.2
PORTREVISION=	9
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Free implementation of the Kerberos 5 network security system

LIB_DEPENDS=	libidn.so:dns/libidn \
		libtasn1.so:security/libtasn1 \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls

USES=		iconv libtool makeinfo pathfix perl5 pkgconfig
USE_LDCONFIG=	yes
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-db-dir=/var/shishi
MAKE_ENV=	MAKEINFOFLAGS=--no-split
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

INFO=		shishi

SUB_FILES=	pkg-message

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

post-extract:
	@${RM} ${WRKSRC}/doc/shishi.info*
	@cd ${WRKSRC}/db/gl && ${LN} -s ../../build-aux/link-warning.h

post-patch:
	@${REINPLACE_CMD} -e 's/$$(LINK_WARNING_H)/link-warning.h/' \
		${WRKSRC}/db/gl/Makefile.in
	@${REINPLACE_CMD} -e 's:\.\./gl/libgnu.la:../db/gl/libgnu.la &:' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/^AM_CPPFLAGS/s:-I[^ ]*/gl ::g' \
		${WRKSRC}/examples/Makefile.in

.include <bsd.port.mk>
