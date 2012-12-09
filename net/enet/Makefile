# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	enet
PORTVERSION=	1.3.5
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://enet.bespin.org/download/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple and robust communication library based on UDP

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS

USE_AUTOTOOLS=	aclocal automake autoconf libtool
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s|$$(libdir)|$$(prefix)/libdata|' \
		${WRKSRC}/Makefile.am

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} html ${DOCSDIR})
.endif

.include <bsd.port.mk>
