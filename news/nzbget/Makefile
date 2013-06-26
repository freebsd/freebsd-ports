# Created by: Lewis Thompson <purple@lewiz.net>
# $FreeBSD$

PORTNAME=	nzbget
PORTVERSION=	10.2
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	toxic@doobie.com
COMMENT=	Binary newsreader supporting NZB files

LICENSE=	GPLv2

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		sigc-2:${PORTSDIR}/devel/libsigc++20

USE_RC_SUBR=	nzbget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"
MAKE_JOBS_UNSAFE=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}
USE_GMAKE=	yes

PAR_DESC=	Support verifying/repairing with par2 files
OPTIONS_DEFINE=	PAR
OPTIONS_SINGLE=	TLSLIB
OPTIONS_SINGLE_TLSLIB=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	PAR GNUTLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPAR}
 CONFIGURE_ARGS+= --enable-parcheck --disable-libpar2-bugfixes-check
 LIB_DEPENDS+=	par2:${PORTSDIR}/archivers/libpar2
.else
 CONFIGURE_ARGS+= --disable-parcheck
.endif

.if ${PORT_OPTIONS:MOPENSSL}
 USE_OPENSSL=	yes
 CONFIGURE_ARGS+= --with-tlslib=OpenSSL \
		--with-openssl-includes=${OPENSSLINC} \
		--with-openssl-libraries=${OPENSSLLIB}
.endif

.if ${PORT_OPTIONS:MGNUTLS}
 CONFIGURE_ARGS+=	--with-tlslib=GnuTLS
 LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
 LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/nzbget.conf ${PREFIX}/etc/nzbget.conf.sample
	@[ -f ${PREFIX}/etc/nzbget.conf ] || ${CP} ${PREFIX}/etc/nzbget.conf.sample \
	${PREFIX}/etc/nzbget.conf

.include <bsd.port.mk>
