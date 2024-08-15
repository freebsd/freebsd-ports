PORTNAME=	bundler
PORTVERSION=	2.5.14
PORTEPOCH=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool that manages gem dependencies for Ruby applications
WWW=		https://bundler.io/ \
		https://github.com/rubygems/rubygems/tree/master/bundler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe gem

CONFLICTS_INSTALL=	go-tools # bin/bundle

NO_ARCH=	yes

PLIST_FILES=	bin/bundle \
		bin/bundler \
		share/man/man1/bundle-add.1.gz \
		share/man/man1/bundle-binstubs.1.gz \
		share/man/man1/bundle-cache.1.gz \
		share/man/man1/bundle-check.1.gz \
		share/man/man1/bundle-clean.1.gz \
		share/man/man1/bundle-config.1.gz \
		share/man/man1/bundle-console.1.gz \
		share/man/man1/bundle-doctor.1.gz \
		share/man/man1/bundle-exec.1.gz \
		share/man/man1/bundle-gem.1.gz \
		share/man/man1/bundle-help.1.gz \
		share/man/man1/bundle-info.1.gz \
		share/man/man1/bundle-init.1.gz \
		share/man/man1/bundle-inject.1.gz \
		share/man/man1/bundle-install.1.gz \
		share/man/man1/bundle-list.1.gz \
		share/man/man1/bundle-lock.1.gz \
		share/man/man1/bundle-open.1.gz \
		share/man/man1/bundle-outdated.1.gz \
		share/man/man1/bundle-platform.1.gz \
		share/man/man1/bundle-plugin.1.gz \
		share/man/man1/bundle-pristine.1.gz \
		share/man/man1/bundle-remove.1.gz \
		share/man/man1/bundle-show.1.gz \
		share/man/man1/bundle-update.1.gz \
		share/man/man1/bundle-version.1.gz \
		share/man/man1/bundle-viz.1.gz \
		share/man/man1/bundle.1.gz \
		share/man/man5/gemfile.5.gz

post-install:
.for i in 1 5
	for f in ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/bundler/man/*.${i}; do \
		${GZIP_CMD} $${f}; \
		${RLN} $${f}.gz ${STAGEDIR}${PREFIX}/share/man/man${i}/$$(basename $${f}).gz; \
	done
.endfor

.include <bsd.port.mk>
