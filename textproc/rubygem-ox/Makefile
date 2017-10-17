# $FreeBSD$

PORTNAME=	ox
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Speed-optimized XML parser and object serializer for Ruby

LICENSE=	MIT

USES=		gem
USE_RUBY=	yes

# The original gem depends on ext/ox/ox.so,
# but the ext directory is eliminated by FreeBSD's Uses/gem.mk framework.
# The workaround below is to create symlink lib/ox/ox.so pointing to lib/ox.so.

PLIST_FILES=	${GEM_LIB_DIR}/lib/ox/ox.so

post-install:
	${LN} -s ../ox.so ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/ox

.include <bsd.port.mk>
