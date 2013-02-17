# $FreeBSD$

PORTNAME=	nzbget
PORTVERSION=	9.1
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	toxic@doobie.com
COMMENT=	A binary newsreader supporting NZB files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		sigc-2:${PORTSDIR}/devel/libsigc++20

USE_RC_SUBR=	nzbget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"
MAKE_JOBS_UNSAFE=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}
USE_GMAKE=	yes

OPTIONS_DEFINE=	PARCHECK GNUTLS OPENSSL
OPTIONS_DEFAULT=	PARCHECK GNUTLS
PARCHECK_DESC=	Enable autopar/parcheck

PORTDOCS=	README

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPARCHECK}
CONFIGURE_ARGS+=	--enable-parcheck
LIB_DEPENDS+=	par2:${PORTSDIR}/archivers/libpar2
.else
CONFIGURE_ARGS+=	--without-parcheck
.endif

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--with-tlslib=OpenSSL
.endif

.if ${PORT_OPTIONS:MGNUTLS}
CONFIGURE_ARGS+=	--with-tlslib=GnuTLS
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
