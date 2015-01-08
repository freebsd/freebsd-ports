# Created by: Edson Brandi <ebrandi@fugspbr.org>
# $FreeBSD$

PORTNAME=	dar
PORTVERSION=	2.4.15
PORTREVISION=	1
CATEGORIES=	sysutils archivers
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command-line backup tool, aimed for disks

LICENSE=	GPLv2 # (or later)

USES=		libtool shebangfix
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

OPTIONS_DEFINE=		DOCS GCRYPT LZO NLS
OPTIONS_SUB=		yes

GCRYPT_CONFIGURE_OFF=	--disable-libgcrypt-linking
GCRYPT_LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
LZO_DESC=		Support lzo compression via liblzo2
LZO_LIB_DEPENDS=	liblzo2.so:${PORTSDIR}/archivers/lzo2
LZO_CONFIGURE_OFF=	--disable-liblzo2-linking
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|(char \*\*) \(\&inptr,\)|\1| ; \
		 /LIBS/s|-lpthread|-pthread|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC}/doc -name "Makefile.in" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|$$(pkgdatadir)|$$(docdir)|g'
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|src doc|src|' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
