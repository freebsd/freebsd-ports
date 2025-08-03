PORTNAME=	dar
DISTVERSION=	2.8.0
CATEGORIES=	sysutils archivers
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command-line backup tool, aimed for disks
WWW=		http://dar.linux.free.fr/

LICENSE=	GPLv2+

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error

USES=		compiler:c++14-lang libtool localbase shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	doc/samples/*.bash doc/samples/*.sh doc/samples/dar_backup \
		doc/samples/date_past_N_days

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--disable-build-html \
		--disable-dar-static \
		--disable-ea-support \
		--disable-gnugetopt \
		--disable-libcurl-linking \
		--disable-nodump-flag \
		--disable-upx

INSTALL_TARGET=	install-strip

PLIST_SUB=	SHLIB_VER=7000.0.0

OPTIONS_DEFINE=		ARGON2 BZIP2 DELTA DOCS GCRYPT GPGME LZ4 LZMA LZO \
			MULTITHR NLS ZLIB ZSTD
OPTIONS_DEFAULT=	ARGON2 BZIP2 DELTA GCRYPT LZ4 LZMA LZO MULTITHR ZLIB \
			ZSTD
OPTIONS_SUB=		yes

ARGON2_DESC=	argon2 hashing algorithm via libargon2
DELTA_DESC=	Binary delta support via librsync
GPGME_DESC=	gpgme for asymetric crypto algorithms
MULTITHR_DESC=	Multithreading support via libthreadar

ARGON2_IMPLIES=		GCRYPT
ARGON2_LIB_DEPENDS=	libargon2.so:security/libargon2
ARGON2_CONFIGURE_OFF=	--disable-libargon2-linking
BZIP2_CONFIGURE_OFF=	--disable-libbz2-linking
DELTA_LIB_DEPENDS=	librsync.so:net/librsync
DELTA_CONFIGURE_OFF=	--disable-librsync-linking
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CONFIGURE_OFF=	--disable-libgcrypt-linking
GPGME_IMPLIES=		GCRYPT
GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPGME_CONFIGURE_OFF=	--disable-gpgme-linking
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_OFF=	--disable-liblz4-linking
LZMA_CONFIGURE_OFF=	--disable-libxz-linking
LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
LZO_CONFIGURE_OFF=	--disable-liblzo2-linking
MULTITHR_LIB_DEPENDS=	libthreadar.so:devel/libthreadar
MULTITHR_CONFIGURE_OFF=	--disable-threadar
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
ZLIB_CONFIGURE_OFF=	--disable-libz-linking
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_CONFIGURE_OFF=	--disable-libzstd-linking

post-patch:
	@${REINPLACE_CMD} -e \
		's|(char \*\*) \(\&inptr,\)|\1| ; \
		 /LIBS/s|-lpthread|-pthread|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC}/doc -name "Makefile.in" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|$$(pkgdatadir)|$$(docdir)|g'

.include <bsd.port.mk>
