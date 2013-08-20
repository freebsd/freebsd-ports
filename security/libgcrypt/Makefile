# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.5.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	General purpose crypto library based on code used in GnuPG

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	libgpg-error>=1.8:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS=	libgpg-error>=1.8:${PORTSDIR}/security/libgpg-error

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
USE_LDCONFIG=	yes

DOCS=		AUTHORS ChangeLog ChangeLog-2011 INSTALL NEWS README \
		README.GIT THANKS TODO doc/HACKING doc/README.apichanges
INFO=		gcrypt
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
CONFIGURE_ARGS+=	--disable-asm
.if (${OSVERSION} >= 1000000)
BROKEN=	will not compile. See pr ports/166388
.endif

.elif ${ARCH} == "armv6"
USE_GCC=4.2+

.elif ${ARCH} == "i386"
.if (${OSVERSION} < 900033)
CONFIGURE_ARGS+=	--disable-aesni-support
#workaround for FreeBSD 10.0
.elif (${OSVERSION} >= 1000000)
CONFIGURE_ARGS+=	--disable-asm
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|" \
		${WRKSRC}/ltmain.sh

pre-configure:
	@${RM} -f ${WRKSRC}/doc/gcrypt.info*

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

regression-test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.post.mk>
