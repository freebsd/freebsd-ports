# Created by: ijliao
# $FreeBSD$

PORTNAME=	gsasl
PORTVERSION=	1.8.1
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GNU SASL Library

LIB_DEPENDS=	libidn.so:dns/libidn \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libntlm.so:security/libntlm

USES=		charsetfix libtool localbase:ldflags pathfix perl5 pkgconfig
USE_PERL5=	build

#CPPFLAGS+=	-nostdinc -I/usr/include -I${LOCALBASE}/include
CPPFLAGS+=	-nostdinc -I/usr/include
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
#LDFLAGS+=	-L/usr/lib -L${LOCALBASE}/lib
LDFLAGS+=	-L/usr/lib
USE_LDCONFIG=	yes

INFO=		gsasl

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e '/^en@/d' ${WRKSRC}/lib/po/LINGUAS ${WRKSRC}/po/LINGUAS

x-post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgsasl.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/reference
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/reference/html/* ${STAGEDIR}${DOCSDIR}/reference

.include <bsd.port.mk>
