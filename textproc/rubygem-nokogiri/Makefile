# $FreeBSD$

PORTNAME=	nokogiri
PORTVERSION=	1.10.9
PORTREVISION=	0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTML, XML, SAX, and Reader parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error
# Do not add mini_portile2 to RUN_DEPENDS. Read ext/nokogiri/extconf.rb
# and https://lists.freebsd.org/pipermail/svn-ports-all/2019-March/209423.html
RUN_DEPENDS=	rubygem-pkg-config>=1.1.7:devel/rubygem-pkg-config

USES=		gem gnome pkgconfig gettext-runtime
USE_GNOME=	libxml2 libxslt
USE_RUBY=	yes

CONFIGURE_ARGS=	--use-system-libraries

PLIST_FILES=	bin/nokogiri

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR} -name '*.o' -o -name '*.so' | ${XARGS} ${STRIP_CMD}
	${RMDIR} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ports/

.include <bsd.port.mk>
