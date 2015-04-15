# $FreeBSD$

PORTNAME=	nokogiri
PORTVERSION=	1.6.6.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTML, XML, SAX, and Reader parser

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USE_GNOME=	libxml2 libxslt
USES=		pkgconfig
CONFIGURE_ARGS=	--use-system-libraries

PLIST_FILES=	bin/nokogiri

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ext/nokogiri/*.o
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ext/nokogiri/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/nokogiri/*.so

.include <bsd.port.mk>
