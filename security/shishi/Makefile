# $FreeBSD$

PORTNAME=	shishi
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A free implementation of the Kerberos 5 network security system

LIB_DEPENDS=	idn:${PORTSDIR}/dns/libidn \
		tasn1:${PORTSDIR}/security/libtasn1 \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gnutls:${PORTSDIR}/security/gnutls

USE_AUTOTOOLS=	libtool
USE_PERL5=	build
USES=		pathfix pkgconfig iconv perl5
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--with-db-dir=/var/shishi
USE_LDCONFIG=	yes

INFO=		shishi

SUB_FILES=	pkg-message

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include "Makefile.man"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>
