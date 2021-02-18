# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.9.2
CATEGORIES=	security
MASTER_SITES=	GNUPG

MAINTAINER=	cy@FreeBSD.org
COMMENT=	General purpose cryptographic library based on the code from GnuPG

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	libgpg-error>=1.32:security/libgpg-error
RUN_DEPENDS=	libgpg-error>=1.32:security/libgpg-error

USES=		cpe libtool makeinfo tar:bzip2

CPE_VENDOR=	gnupg
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-drng-support --enable-static=yes
CONFIGURE_ENV=	MAKEINFO="${MAKEINFO} --no-split"
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
USE_LDCONFIG=	yes
TEST_TARGET=	check

DOCS=		AUTHORS ChangeLog ChangeLog-2011 INSTALL NEWS THANKS TODO \
		doc/HACKING doc/README.apichanges
INFO=		gcrypt
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "powerpc"
CONFIGURE_ARGS+=	--disable-asm
.endif

post-patch:
	@${RM} ${WRKSRC}/doc/gcrypt.info*
	@${REINPLACE_CMD} -e 's|ALIGN (3)|ALIGN (2)|g' ${WRKSRC}/mpi/i386/*.S

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
