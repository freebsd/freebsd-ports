# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rifiuti2
DISTVERSION=	0.5.1
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Tool for analyzing Windows recycle bin

LICENSE=	BSD

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GNOME=	glib20

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/rifiuti bin/rifiuti-vista

MAN1=		rifiuti.1
MLINKS=		rifiuti.1 rifiuti-vista.1

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README THANKS TODO

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
