# Created by: Lewis Thompson <purple@lewiz.net>
# $FreeBSD$

PORTNAME=	nzbget
PORTVERSION=	20.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	news

MAINTAINER=	toxic@doobie.com
COMMENT=	Binary newsreader supporting NZB files

LICENSE=	GPLv2

LIB_DEPENDS=	libxml2.so:textproc/libxml2

USES=		autoreconf compiler:c++14-lang gmake localbase ncurses pkgconfig shebangfix ssl
USE_RC_SUBR=	nzbget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libcurses-includes=${NCURSESINC} \
		--with-libcurses-libraries=${NCURSESLIB} \
		--with-tlslib=OpenSSL \
		--with-openssl-includes=${OPENSSLINC} \
		--with-openssl-libraries=${OPENSSLLIB}

BINMODE=	0755

SHEBANG_FILES=	scripts/*.py
SUB_FILES=	pkg-message

USE_GITHUB=	yes

OPTIONS_DEFINE=	7Z DOCS OPTIMIZED_FLAGS PYTHON RAR
OPTIONS_DEFAULT=	PAR PYTHON RAR 7Z
7Z_DESC=	Support extraction of 7z archives
OPTIMIZED_FLAGS_DESC=	Enable optimized CPU instructions (SSE2/SSE3/NEON/etc)
PYTHON_DESC=	Support for python post-processing scripts
RAR_DESC=	Support extraction of rar archives

7Z_RUN_DEPENDS=		7z:archivers/p7zip

OPTIMIZED_FLAGS_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-disable-optimized-flags.patch

PYTHON_USES=		python:run

RAR_RUN_DEPENDS=	unrar:archivers/unrar

.include <bsd.port.options.mk>

.if (${ARCH} == "i386")
CONFIGURE_ARGS+=	--disable-sigchld-handler
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/nzbget.conf \
		${STAGEDIR}${PREFIX}/etc/nzbget.conf.sample

.include <bsd.port.mk>
