PORTNAME=	xorriso
DISTVERSION=	1.5.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://files.libburnia-project.org/releases/
DISTNAME=	libisoburn-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISO image manipulation tool based on Libburnia
WWW=		https://dev.lovelyhq.com/libburnia/web/wiki

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libburn.so:devel/libburn \
		libisofs.so:devel/libisofs

USES=		gmake iconv libedit libtool pathfix pkgconfig readline \
		shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	frontend/xorriso-tcltk
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip

INFO=		xorrecord xorriso xorrisofs

PORTDOCS=	*.wiki

OPTIONS_DEFINE=		CDIO DEBUG DOCS LIBACL LIBJTE READLINE TK XATTR ZLIB
OPTIONS_DEFAULT=	LIBACL LIBJTE READLINE XATTR ZLIB
OPTIONS_SUB=		yes

LIBACL_DESC=	ACL Support
LIBJTE_DESC=	Jigdo Support
XATTR_DESC=	Extended file attribute Support

CDIO_LIB_DEPENDS=		libcdio.so:sysutils/libcdio
CDIO_CONFIGURE_ENABLE=		libcdio
DEBUG_CONFIGURE_ENABLE=		debug
LIBACL_CONFIGURE_ENABLE=	libacl
LIBJTE_CONFIGURE_ENABLE=	libjte
READLINE_CONFIGURE_ENABLE=	libreadline
TK_USES=			tk
TK_INFO=			xorriso-tcltk
XATTR_CONFIGURE_ENABLE=		xattr
ZLIB_CONFIGURE_ENABLE=		zlib

post-patch:
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

do-install-TK-off:
	${RM} ${STAGEDIR}${PREFIX}/bin/xorriso-tcltk \
		${STAGEDIR}${PREFIX}/man/man1/xorriso-tcltk.1.gz \
		${STAGEDIR}${PREFIX}/share/info/xorriso-tcltk.info

.include <bsd.port.mk>
