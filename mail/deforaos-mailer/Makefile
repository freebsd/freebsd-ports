PORTNAME=	mailer
PORTVERSION=	0.2.0
CATEGORIES=	mail
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Mailer/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Mailer-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop mail client
WWW=		https://www.defora.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libDesktop.so:x11/deforaos-libdesktop \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libSystem.so:devel/deforaos-libsystem

USES=		gnome pkgconfig ssl xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_LDCONFIG=	yes
USE_XORG=	x11

MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${PREFIX}/share/man

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			gtkdoc-check:textproc/gtk-doc \
			xsltproc:textproc/libxslt

NLS_USES=	gettext

.include <bsd.port.pre.mk>

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|data doc include|data include|' \
		${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|include po src|include src|' \
		${WRKSRC}/Makefile

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
.if ${OPSYS} == FreeBSD
	${REINPLACE_CMD} 's/-fstack-protector/-fstack-protector -Wno-error=int-conversion/g' \
		${WRKSRC}/src/Makefile \
		${WRKSRC}/src/account/Makefile \
		${WRKSRC}/src/plugins/Makefile \
		${WRKSRC}/tests/Makefile
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/Mailer/plugins/*.so \
		${STAGEDIR}${PREFIX}/lib/Mailer/account/*.so \
		${STAGEDIR}${PREFIX}/lib/libMailer.so.0.0

.include <bsd.port.post.mk>
