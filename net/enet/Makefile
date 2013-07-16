# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	enet
PORTVERSION=	1.3.7
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://enet.bespin.org/download/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple and robust communication library based on UDP

LICENSE=	MIT

USE_AUTOTOOLS=	aclocal automake autoconf libtool
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s|$$(libdir)|$$(prefix)/libdata|' \
		${WRKSRC}/Makefile.am

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} html ${DOCSDIR})
.endif

.include <bsd.port.mk>
