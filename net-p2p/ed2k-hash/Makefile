PORTNAME=	ed2k-hash
PORTVERSION=	0.4.0
CATEGORIES=	net-p2p
MASTER_SITES=	SF/ed2k-tools/ed2k_hash/${PORTVERSION}
DISTNAME=	ed2k_hash-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Calculate eD2K hashes and create ed2k:// file links
WWW=		https://ed2k-tools.sourceforge.net/ed2k_hash.shtml

LICENSE=	GPLv2+

USE_CXXSTD=	c++03	# required for FLTK ./configure detection
GNU_CONFIGURE=	yes
MAKE_ARGS=	mydocdir=${DOCSDIR}

PLIST_FILES=	bin/ed2k_hash
PORTDOCS=	index*.html

OPTIONS_DEFINE=	DOCS X11

X11_LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk
X11_USES=		localbase
X11_LIBS=		-lpthread
X11_PLIST_FILES=	bin/ed2k_hash_gui

post-patch:
	@${REINPLACE_CMD} -E 's, ?-O2,,' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's,long int UINT4,int UINT4,' \
		${WRKSRC}/ed2k_hash/md4.h

.include <bsd.port.mk>
