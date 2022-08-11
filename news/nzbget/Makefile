PORTNAME=	nzbget
PORTVERSION=	21.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	news

MAINTAINER=	alexis.praga@free.fr
COMMENT=	Binary newsreader supporting NZB files

LICENSE=	GPLv2

LIB_DEPENDS=	libxml2.so:textproc/libxml2

USES=		autoreconf compiler:c++14-lang cpe gmake localbase ncurses \
		pkgconfig python:build shebangfix ssl
USE_GITHUB=	yes
USE_RC_SUBR=	nzbget

SHEBANG_FILES=	scripts/*.py

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libcurses-includes=${NCURSESINC} \
		--with-libcurses-libraries=${NCURSESLIB} \
		--with-tlslib=OpenSSL \
		--with-openssl-includes=${OPENSSLINC} \
		--with-openssl-libraries=${OPENSSLLIB}

BINMODE=	0755

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS OPTIMIZED_FLAGS
OPTIMIZED_FLAGS_DESC=	Enable optimized CPU instructions (SSE2/SSE3/NEON/etc)
OPTIMIZED_FLAGS_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-disable-optimized-flags.patch

.include <bsd.port.options.mk>

.if (${ARCH} == "i386")
CONFIGURE_ARGS+=	--disable-sigchld-handler
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/nzbget.conf \
		${STAGEDIR}${PREFIX}/etc/nzbget.conf.sample

.include <bsd.port.mk>
