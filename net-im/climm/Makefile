# New ports collection makefile for:	micq
# Date created:				11 Oct 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	climm
PORTVERSION=	0.6
CATEGORIES=	net-im
MASTER_SITES=	http://www.climm.org/source/ \
		http://http.bg.climm.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@stack.nl
COMMENT=	CLI-based Multi-Messenger

USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		climm.1
MAN5=		climmrc.5
MAN7=		climmcmds.7

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
	${INSTALL_MAN} ${WRKSRC}/doc/climm.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/climmrc.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/climmcmds.7 ${MANPREFIX}/man/man7
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ext in i18n logformat png txt xpm
	${INSTALL_DATA} ${WRKSRC}/doc/*.${ext} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
