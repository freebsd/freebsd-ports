# Created by: Rafael Ostertag <rafi@guengel.ch>
# $FreeBSD$

PORTNAME=	yapet
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	http://www.guengel.ch/myapps/yapet/downloads/ http://homepage.hispeed.ch/rostertag/yapet/

MAINTAINER=	rafi@guengel.ch
COMMENT=	Curses based password manager

MAN1=		yapet.1
MANCOMPRESSED=	no

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	TTITLE PWGEN CSV2YAPET DOCS
OPTIONS_DEFAULT=	TTITLE PWGEN CSV2YAPET
TTITLE_DESC=	Enable Terminal Title
PWGEN_DESC=	Enable Password Generator
CSV2YAPET_DESC=	Build csv2yapet

NO_STAGE=	yes
.include <bsd.port.options.mk>

# --enable-silent-rules:  will make the build quiet
# --disable-install-doc:  I take care of installing docs
CONFIGURE_ARGS+=	--enable-silent-rules --disable-install-doc

.if ${PORT_OPTIONS:MTTITLE}
CONFIGURE_ARGS+=	--enable-terminal-title
.else
CONFIGURE_ARGS+=	--disable-terminal-title
.endif

.if ${PORT_OPTIONS:MPWGEN}
CONFIGURE_ARGS+=	--enable-pwgen
.else
CONFIGURE_ARGS+=	--disable-pwgen
.endif

.if ${PORT_OPTIONS:MCSV2YAPET}
CONFIGURE_ARGS+=	--enable-csv2yapet
MAN1+=			csv2yapet.1
PLIST_SUB+=		CSV2YAPET=""
.else
CONFIGURE_ARGS+=	--disable-csv2yapet
PLIST_SUB+=		CSV2YAPET="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=			gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=		NOPORTDOCS=""
.else
PLIST_SUB+=		NOPORTDOCS="@comment "
.endif

# Taking care of installing docs due to --disable-install-doc
# configure switch.
post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/DESIGN ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/THANKS ${DOCSDIR}
.endif

.include <bsd.port.mk>
