# Created by: Lewis Thompson <purple@lewiz.net>
# $FreeBSD$

PORTNAME=	nzbget
PORTVERSION=	11.0
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	toxic@doobie.com
COMMENT=	Binary newsreader supporting NZB files

LICENSE=	GPLv2

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20

USES=		pkgconfig
USE_RC_SUBR=	nzbget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"
MAKE_JOBS_UNSAFE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}

OPTIONS_DEFINE=	7Z PAR PYTHON RAR
OPTIONS_SINGLE=	TLSLIB
OPTIONS_SINGLE_TLSLIB=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	GNUTLS PAR PYTHON RAR
7Z_DESC=	Support extraction of 7z archives
PAR_DESC=	Support verifying/repairing with par2 files
PYTHON_DESC=	Support for python post-processing scripts
RAR_DESC=	Support extraction of rar archives

7Z_RUN_DEPENDS=		7z:${PORTSDIR}/archivers/p7zip

PAR_CONFIGURE_ON=	--enable-parcheck --disable-libpar2-bugfixes-check
PAR_CONFIGURE_OFF=	--disable-parcheck
PAR_LIB_DEPENDS=	libpar2.so:${PORTSDIR}/archivers/libpar2

PYTHON_USE=	PYTHON=yes

RAR_RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar

OPENSSL_CONFIGURE_ON=	--with-tlslib=OpenSSL \
			--with-openssl-includes=${OPENSSLINC} \
			--with-openssl-libraries=${OPENSSLLIB}
OPENSSL_USE=	OPENSSL=yes

GNUTLS_CONFIGURE_ON=	--with-tlslib=GnuTLS
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
			libgcrypt.so:${PORTSDIR}/security/libgcrypt

.include <bsd.port.options.mk>

.if (${ARCH} == "i386")
CONFIGURE_ARGS+=       --disable-sigchld-handler
.endif

post-configure:
	# necessary for stage
	@${REINPLACE_CMD} -e 's|555|655|g ; s|444|644|' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/nzbget.conf \
		${STAGEDIR}${PREFIX}/etc/nzbget.conf.sample

.include <bsd.port.mk>
