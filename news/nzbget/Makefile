PORTNAME=	nzbget
PORTVERSION=	24.1
DISTVERSIONPREFIX=	v
CATEGORIES=	news

MAINTAINER=	alexis.praga@free.fr
COMMENT=	Binary newsreader supporting NZB files
WWW=		https://nzbget.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_json.so:devel/boost-libs \
		libxml2.so:textproc/libxml2
RUN_DEPENDS=	7-zip>0:archivers/7-zip \
		unrar>0:archivers/unrar

USES=		cmake ncurses python:build ssl
USE_GITHUB=	yes
GH_ACCOUNT=	nzbgetcom
GH_PROJECT=	nzbget
USE_RC_SUBR=	nzbget

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libcurses-includes=${NCURSESINC} \
		--with-libcurses-libraries=${NCURSESLIB} \
		--with-openssl-includes=${OPENSSLINC} \
		--with-openssl-libraries=${OPENSSLLIB} \
		--with-tlslib=OpenSSL

BINMODE=	0755

SUB_FILES=	pkg-message

OPTIONS_DEFINE=				DOCS OPTIMIZED_FLAGS
OPTIMIZED_FLAGS_DESC=			Enable optimized CPU instructions (SSE2/SSE3/NEON/etc)
OPTIMIZED_FLAGS_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-disable-optimized-flags.patch

.include <bsd.port.options.mk>

.if (${ARCH} == "i386")
CONFIGURE_ARGS+=	--disable-sigchld-handler
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/nzbget.conf \
		${STAGEDIR}${PREFIX}/etc/nzbget.conf.sample

.include <bsd.port.mk>
