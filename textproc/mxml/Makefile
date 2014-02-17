# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mxml
PORTVERSION=	2.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.msweet.org/files/project3/

MAINTAINER=	hsmtkk@gmail.com
COMMENT=	Small XML parsing library

LICENSE=	MXML
LICENSE_NAME=	Mini-XML License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
USES=		gmake
USE_AUTOTOOLS=	libtool
USES=		pathfix desthack
CONFIGURE_ARGS=	--with-docdir=no
USE_LDCONFIG=	yes

PORTDOCS=	*

PLIST_FILES=	bin/mxmldoc include/mxml.h \
		lib/libmxml.a \
		lib/libmxml.so lib/libmxml.so.1 lib/libmxml.so.1.5 \
		libdata/pkgconfig/mxml.pc \
		man/man1/mxmldoc.1.gz \
		man/man3/mxml.3.gz

OPTIONS_DEFINE=	DOCS 

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
