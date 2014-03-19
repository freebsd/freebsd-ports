# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hiera
PORTVERSION=	1.3.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@robakdesign.com
COMMENT=	Pluggable data store for hierarchical data

LICENSE=	APACHE20

RUN_DEPENDS=	${PKGNAMEPREFIX}json_pure>=0:${PORTSDIR}/devel/rubygem-json_pure

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
HIERA_DBDIR=	/var/db/hiera
PLIST_FILES=	bin/hiera
PLIST_DIRS=	${HIERA_DBDIR}

post-install:
	@${REINPLACE_CMD} "s!/etc/hiera.yaml!${STAGEDIR}${PREFIX}/etc/hiera.yaml!" \
		${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/bin/hiera \
		${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/hiera.rb \
		${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/spec/unit/hiera_spec.rb
	@${REINPLACE_CMD} "s!/var/lib/hiera!${HIERA_DBDIR}!" \
		${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/hiera/backend.rb \
		${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/spec/unit/backend_spec.rb
	@${FIND} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR} -name \*.bak -delete
	@${MKDIR} ${STAGEDIR}${HIERA_DBDIR}

.include <bsd.port.mk>
