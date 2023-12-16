PORTNAME=	nokogiri
PORTVERSION=	1.15.5
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTML, XML, SAX, and Reader parser
WWW=		https://nokogiri.org/ \
		https://github.com/sparklemotion/nokogiri

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${RUN_DEPENDS} \
		rubygem-mini_portile2>=2.8.2<2.9:devel/rubygem-mini_portile2 \
		rubygem-pkg-config>=1.1<2:devel/rubygem-pkg-config
# Do not add mini_portile2 to RUN_DEPENDS. Read ext/nokogiri/extconf.rb
# and https://lists.freebsd.org/pipermail/svn-ports-all/2019-March/209423.html
RUN_DEPENDS=	rubygem-racc>=1.4<2:devel/rubygem-racc

USES=		cpe gem gnome gettext-runtime
USE_GNOME=	libxml2 libxslt

CONFIGURE_ARGS=	--use-system-libraries

PLIST_FILES=	bin/nokogiri

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ports/

.include <bsd.port.mk>
