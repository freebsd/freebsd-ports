# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	xorriso
PORTVERSION=	1.5.0
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://files.libburnia-project.org/releases/
DISTNAME=	libisoburn-${PORTVERSION}

MAINTAINER=	ndowens@yahoo.com
COMMENT=	ISO image manipulation tool based on Libburnia

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libburn.so:devel/libburn \
		libisofs.so:devel/libisofs

USES=		gmake iconv libtool libedit pathfix pkgconfig readline shebangfix
SHEBANG_FILES=	frontend/xorriso-tcltk
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

INFO=		xorrecord xorriso xorrisofs

PORTDOCS=	*.wiki

OPTIONS_DEFINE=	CDIO DEBUG DOCS LIBACL LIBJTE READLINE TK XATTR ZLIB
OPTIONS_DEFAULT=LIBACL LIBJTE READLINE XATTR ZLIB
OPTIONS_SUB=	yes

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

do-install-TK-off:
	${RM} ${STAGEDIR}${PREFIX}/bin/xorriso-tcltk \
		${STAGEDIR}${PREFIX}/man/man1/xorriso-tcltk.1.gz \
		${STAGEDIR}${PREFIX}/share/info/xorriso-tcltk.info

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
