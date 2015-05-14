# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.6.3
CATEGORIES=	security
MASTER_SITES=	GNUPG

MAINTAINER=	cpm@fbsd.es
COMMENT=	General purpose crypto library based on code used in GnuPG

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	libgpg-error>=1.8:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS=	libgpg-error>=1.8:${PORTSDIR}/security/libgpg-error

USES=		cpe libtool makeinfo tar:bzip2
CPE_VENDOR=	gnupg
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-drng-support
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
USE_LDCONFIG=	yes

DOCS=		AUTHORS ChangeLog ChangeLog-2011 INSTALL NEWS README \
		README.GIT THANKS TODO doc/HACKING doc/README.apichanges
INFO=		gcrypt
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "powerpc"
CONFIGURE_ARGS+=	--disable-asm

.elif ${ARCH} == "i386"
.if (${OSVERSION} < 900033)
CONFIGURE_ARGS+=	--disable-aesni-support
.endif

.endif

post-patch:
	${RM} -f ${WRKSRC}/doc/gcrypt.info*
	${REINPLACE_CMD} -e 's|ALIGN (3)|ALIGN (2)|g' ${WRKSRC}/mpi/i386/*.S

# Fix build without ASM on 8.x/amd64
.if ${OPSYS} == FreeBSD && ${ARCH} == "amd64" && ${OSVERSION} < 900000
USE_GCC=	any
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-configure
.endif

# Fix crash at cipher/salsa20.c module on amd64
.if ${ARCH} == "amd64" && exists(/usr/bin/clang)
CFLAGS:=	${CFLAGS:N-O*} -O2
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.20.0.3

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

regression-test: build
	cd ${WRKSRC} && ${MAKE_CMD} check

.include <bsd.port.mk>
