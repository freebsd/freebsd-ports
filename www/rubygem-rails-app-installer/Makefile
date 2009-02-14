# New ports collection makefile for:	www/rubygem-rails-app-installer
# Date created:				15 September 2006
# Whom:					Geraud Continsouzas <geraud@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	rails-app-installer
PORTVERSION=	0.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	rails-installer

MAINTAINER=	geraud@gcu.info
COMMENT=	An installer for Rails apps

BUILD_DEPENDS=	rubygem-sqlite3>=1.1.0:${PORTSDIR}/databases/rubygem-sqlite3 \
		rubygem-mongrel>=0.3.13:${PORTSDIR}/www/rubygem-mongrel \
		rubygem-mongrel_cluster>=0.2.0:${PORTSDIR}/www/rubygem-mongrel_cluster
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rails-app-installer-setup \
		bin/rails-backup \
		bin/rails-restore

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,^${GEM_CACHE}$$,%%GEM_CACHE%%,g \
		;s,${GEM_DOC_DIR}(/.+)?$$,%%GEM_DOC_DIR%%\1,g \
		;s,${GEM_LIB_DIR}(/.+)?$$,%%GEM_LIB_DIR%%\1,g \
		;s,^${GEM_SPEC}$$,%%GEM_SPEC%%,g \
		;s,^${GEMS_BASE_DIR}/(.+)$$,\1,g \
		;s,^@dirrm (${SPEC_DIR}|${GEMS_DIR}|lib/ruby).*$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
