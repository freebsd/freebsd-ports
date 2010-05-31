# New ports collection makefile for:	yapet
# Date created:		01 March 2008
# Whom:			Rafael Ostertag <rafi@guengel.ch>
#
# $FreeBSD$
#

PORTNAME=	yapet
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.guengel.ch/myapps/yapet/downloads/ http://homepage.hispeed.ch/rostertag/yapet/

MAINTAINER=	rafi@guengel.ch
COMMENT=	A curses based password manager

MAN1=		yapet.1
MANCOMPRESSED=	no

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

OPTIONS=	TTITLE "Enable Terminal Title" ON \
		PWGEN "Enable Password Generator" ON \
		CSV2YAPET "Build csv2yapet" ON

.include <bsd.port.pre.mk>

# --enable-silent-rules:  will make the build quiet
# --disable-install-doc:  I take care of installing docs
CONFIGURE_ARGS+=	--enable-silent-rules --disable-install-doc

.if defined(WITH_TTITLE)
CONFIGURE_ARGS+=	--enable-terminal-title
.else
CONFIGURE_ARGS+=	--disable-terminal-title
.endif

.if defined(WITH_PWGEN)
CONFIGURE_ARGS+=	--enable-pwgen
.else
CONFIGURE_ARGS+=	--disable-pwgen
.endif

.if defined(WITH_CSV2YAPET)
CONFIGURE_ARGS+=	--enable-csv2yapet
MAN1+=			csv2yapet.1
PLIST_SUB+=		CSV2YAPET=""
.else
CONFIGURE_ARGS+=	--disable-csv2yapet
PLIST_SUB+=		CSV2YAPET="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" \
			LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if !defined(NOPORTDOCS)
PLIST_SUB+=		NOPORTDOCS=""
.else
PLIST_SUB+=		NOPORTDOCS="@comment "
.endif

# Taking care of installing docs due to --disable-install-doc
# configure switch.
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/DESIGN ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/THANKS ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
