# New ports collection makefile for:	micq
# Date created:				11 Oct 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	micq
PORTVERSION=	0.5.1
CATEGORIES=	net-im
MASTER_SITES=	http://micq.org/source/ \
		http://micq.alpha345.com/source/ \
		http://http.bg.micq.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	buetow@buetow.org
COMMENT=	Text-based ICQ implementation

USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		micq.1
MAN5=		micqrc.5
MAN7=		micq.7

.if defined(WITHOUT_LIBICONV)
CONFIGURE_ARGS+=	--disable-iconv
.else
USE_ICONV=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -liconv
.endif

.if defined(WITHOUT_UTF8)
CONFIGURE_ARGS+=	--disable-utf8
.endif

.if defined(WITHOUT_P2P)
CONFIGURE_ARGS+=	--disable-peer2peer
.endif

.if defined(WITHOUT_P2P) || defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if defined(WITHOUT_TCL)
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if defined(WITHOUT_REMOTE)
CONFIGURE_ARGS+=	--disable-remote
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/ doc//' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/micq.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/micqrc.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/micq.7 ${MANPREFIX}/man/man7
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ext in i18n logformat png txt xpm
	${INSTALL_DATA} ${WRKSRC}/doc/*.${ext} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
