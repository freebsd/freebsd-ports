# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.6.1
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	General purpose crypto library based on code used in GnuPG

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	libgpg-error>=1.8:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS=	libgpg-error>=1.8:${PORTSDIR}/security/libgpg-error

USES=		libtool makeinfo tar:bzip2
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
INSTALL_TARGET=	install-strip
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

CONFIGURE_ARGS+=	--disable-drng-support

.endif

post-patch:
	${RM} -f ${WRKSRC}/doc/gcrypt.info*
	${REINPLACE_CMD} -e 's|ALIGN (3)|ALIGN (2)|g' ${WRKSRC}/mpi/i386/*.S

# Fix build without ASM on 8.x/amd64
.if ${OPSYS} == FreeBSD && ${ARCH} == "amd64" && ${OSVERSION} < 900000
USE_GCC=	any
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-configure
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

regression-test: build
	cd ${WRKSRC} && ${MAKE_CMD} check

.include <bsd.port.mk>
