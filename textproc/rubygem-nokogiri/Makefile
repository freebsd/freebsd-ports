PORTNAME=	nokogiri
PORTVERSION=	1.13.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTML, XML, SAX, and Reader parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${RUN_DEPENDS} \
		rubygem-mini_portile2>=2.8.0<2.9:devel/rubygem-mini_portile2
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libxml2.so:textproc/libxml2
# Do not add mini_portile2 to RUN_DEPENDS. Read ext/nokogiri/extconf.rb
# and https://lists.freebsd.org/pipermail/svn-ports-all/2019-March/209423.html
RUN_DEPENDS=	rubygem-pkg-config>=1.1.7:devel/rubygem-pkg-config  \
		rubygem-racc>=1.4<2:devel/rubygem-racc

USES=		cpe gem gnome pkgconfig gettext-runtime
USE_GNOME=	libxml2 libxslt
USE_RUBY=	yes

CONFIGURE_ARGS=	--use-system-libraries

PLIST_FILES=	bin/nokogiri

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR} -name '*.o' -o -name '*.so' | ${XARGS} ${STRIP_CMD}
	${RMDIR} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ports/

.include <bsd.port.mk>
