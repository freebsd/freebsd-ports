# New ports collection makefile for:	nzbget
# Date created:				13 April 2004
# Whom:					Lewis Thompson <purple@lewiz.net>
#
# $FreeBSD$
#

PORTNAME=	nzbget
PORTVERSION=	0.7.0
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	toxic@doobie.com
COMMENT=	A binary newsreader supporting NZB files

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		sigc-2:${PORTSDIR}/devel/libsigc++20

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}" \
		LOCALBASE="${LOCALBASE}"
USE_GMAKE=	yes

OPTIONS=	PARCHECK "Enable autopar/parcheck (Requires libpar2)" On
OPTIONS+=	TLSCHECK "Use GNUTLS for SSL" On
OPTIONS+=	OSSLCHECK "Use OpenSSL for SSL" Off

PLIST_FILES=	bin/nzbget
PORTDOCS=	README
PORTEXAMPLES=	nzbget.conf.example

.include <bsd.port.pre.mk>

.if defined (WITHOUT_PARCHECK)
CONFIGURE_ARGS+=	--disable-parcheck
.else
CONFIGURE_ARGS+=	--enable-parcheck
LIB_DEPENDS+=	par2:${PORTSDIR}/archivers/libpar2
.endif

.if defined (WITH_OSSLCHECK)
CONFIGURE_ARGS+=	--with-tlslib=OpenSSL
.endif

.if defined (WITH_TLSCHECK)
CONFIGURE_ARGS+=	--with-tlslib=GnuTLS
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/nzbget.conf.example ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
