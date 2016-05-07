# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hiera
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Pluggable data store for hierarchical data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-json_pure>=0:devel/rubygem-json_pure

CONFLICTS_INSTALL=	rubygem-hiera-*

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem
HIERA_DBDIR=	/var/db/hiera
PLIST_FILES=	bin/hiera
PLIST_DIRS=	${HIERA_DBDIR}

post-install:
	@${REINPLACE_CMD} "s!/etc!${PREFIX}/etc!" \
		${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/hiera/util.rb \
		${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/spec/unit/util_spec.rb
	@${REINPLACE_CMD} "s!/var/lib/hiera!${HIERA_DBDIR}!" \
		${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/hiera/backend.rb \
		${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/hiera/util.rb \
		${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/spec/unit/util_spec.rb
	@${FIND} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR} -name \*.bak -delete
	@${MKDIR} ${STAGEDIR}${HIERA_DBDIR}

.include <bsd.port.mk>
