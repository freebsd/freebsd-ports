# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	cdcollect
PORTVERSION=	0.6.0
PORTREVISION=	7
CATEGORIES=	misc gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}_source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple CD catalog for GNOME

BUILD_DEPENDS=	sqlite3>=3.0:databases/sqlite3
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		tar:bzip2 pathfix gettext gmake mono pkgconfig
USE_GNOME=	gnomeprefix intlhack libgnome gnomesharp20
GCONF_SCHEMAS=	cdcollect.schemas
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-extract:
	${REINPLACE_CMD} -e 's,SqliteClient,Sqlite,' \
	    ${WRKSRC}/src/Makefile.in \
	    ${WRKSRC}/src/CDIcon.cs \
	    ${WRKSRC}/src/CDItem.cs \
	    ${WRKSRC}/src/CompPluginWindow.cs \
	    ${WRKSRC}/src/DBsql.cs

.include <bsd.port.mk>
