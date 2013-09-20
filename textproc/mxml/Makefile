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
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USES=	pathfix
CONFIGURE_ARGS=	--with-docdir=no
USE_LDCONFIG=	yes

MAN1=	mxmldoc.1
MAN3=	mxml.3

PORTDOCS=	*

PLIST_FILES=	bin/mxmldoc include/mxml.h \
		lib/libmxml.a \
		lib/libmxml.so lib/libmxml.so.1 lib/libmxml.so.1.5 \
		libdata/pkgconfig/mxml.pc

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.mk>
