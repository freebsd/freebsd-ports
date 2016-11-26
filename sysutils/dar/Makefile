# Created by: Edson Brandi <ebrandi@fugspbr.org>
# $FreeBSD$

PORTNAME=	dar
PORTVERSION=	2.5.5
PORTREVISION=	1
CATEGORIES=	sysutils archivers
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command-line backup tool, aimed for disks

LICENSE=	GPLv2+

USES=		compiler:c++11-lang libtool shebangfix
SHEBANG_FILES=	doc/samples/dar_backup doc/samples/*.bash doc/samples/*.sh
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} --disable-build-html \
		--disable-upx \
		--disable-ea-support --disable-nodump-flag \
		--disable-gnugetopt --disable-dar-static \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		GCRYPT GPGME LZO ZLIB BZIP2 LZMA DOCS NLS
OPTIONS_DEFAULT=	BZIP2 LZMA LZO ZLIB
OPTIONS_SUB=		yes

ZLIB_CONFIGURE_OFF=	--disable-libz-linking
BZIP2_CONFIGURE_OFF=	--disable-libbz2-linking
LZMA_CONFIGURE_OFF=	--disable-libxz-linking
GPGME_DESC=		gpgme for asymetric crypto algorithms
GPGME_CONFIGURE_OFF=	--disable-gpgme-linking
GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPGME_IMPLIES=		GCRYPT
GCRYPT_CONFIGURE_OFF=	--disable-libgcrypt-linking
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
LZO_DESC=		Support lzo compression via liblzo2
LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
LZO_CONFIGURE_OFF=	--disable-liblzo2-linking
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		's|(char \*\*) \(\&inptr,\)|\1| ; \
		 /LIBS/s|-lpthread|-pthread|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC}/doc -name "Makefile.in" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|$$(pkgdatadir)|$$(docdir)|g'

.include <bsd.port.mk>
