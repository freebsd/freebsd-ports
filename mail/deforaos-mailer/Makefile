PORTNAME=	mailer
PORTVERSION=	0.1.7
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.defora.org/os/download/download/4426/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Mailer-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop mail client
WWW=		https://www.defora.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libDesktop.so:x11/deforaos-libdesktop

USES=		gnome pkgconfig ssl
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_LDCONFIG=	yes

MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
NLS_USES=	gettext

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
# openssl from base doesn't install a .pc file and pkg-config didn't like it
CONFIGURE_ENV+=	libssl_CFLAGS="-I${OPENSSLINC}" libssl_LIBS="-L${OPENSSLLIB} -lssl"
.endif

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|data doc include|data include|' \
		${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|include po src|include src|' \
		${WRKSRC}/Makefile

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
	${REINPLACE_CMD} 's/-lssl/& -lcrypto/' \
		${WRKSRC}/src/Makefile ${WRKSRC}/src/account/Makefile \
		${WRKSRC}/src/plugins/Makefile ${WRKSRC}/tests/Makefile
	${REINPLACE_CMD} 's|-Wl,-pie||g' \
		${WRKSRC}/src/Makefile \
		${WRKSRC}/tests/Makefile
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
	${REINPLACE_CMD} 's/stack-protector-all/stack-protector-all -Wno-error=int-conversion/g' \
		${WRKSRC}/src/Makefile \
		${WRKSRC}/src/account/Makefile \
		${WRKSRC}/src/plugins/Makefile \
		${WRKSRC}/tests/Makefile
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/Mailer/plugins/* \
		${STAGEDIR}${PREFIX}/lib/Mailer/account/* \
		${STAGEDIR}${PREFIX}/lib/libMailer.so.0.0

.include <bsd.port.post.mk>
