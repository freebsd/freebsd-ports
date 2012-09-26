# $FreeBSD$

PORTNAME=	libexttextcat
PORTVERSION=	3.3.1
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/libexttextcat/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Language guessing by N-Gram-Based Text Categorization

LICENSE=	BSD

CONFLICTS_INSTALL=	libtextcat*

USE_XZ=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

PORTDOCS=	README README.libtextcat TODO

OPTIONS_DEFINE= COMPAT_TEXTCAT DOCS
COMPAT_TEXTCAT_DESC=	Install libtextcat compatible files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPAT_TEXTCAT}
PLIST_SUB+=	TEXTCAT=''
.else
PLIST_SUB+=	TEXTCAT='@comment '
.endif

post-install:
.if ${PORT_OPTIONS:MCOMPAT_TEXTCAT}
	${LN} -sf libexttextcat/textcat.h ${PREFIX}/include/
	${LN} -sf libexttextcat ${PREFIX}/include/libtextcat
	${LN} -sf libexttextcat-1.0.a ${PREFIX}/lib/libtextcat.a
	${LN} -sf libexttextcat-1.0.la ${PREFIX}/lib/libtextcat.la
	${LN} -sf libexttextcat-1.0.so.0 ${PREFIX}/lib/libtextcat.so
	${LN} -sf libexttextcat-1.0.so.0 ${PREFIX}/lib/libtextcat.so.0
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

check:
	cd ${WRKSRC}/src && make check

.include <bsd.port.mk>
