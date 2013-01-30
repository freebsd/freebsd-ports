# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	npm
PORTVERSION=	1.2.0
CATEGORIES=	www
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Node package manager

LICENSE=	MIT

OPTIONS_DEFINE=	NODE_DEVEL
NODE_DEVEL_DESC=Use www/node-devel instead of www/node

NO_BUILD=	yes
NO_MANCOMPRESS=	yes
USE_XZ=		yes

MAN1=		README.1 adduser.1 bin.1 bugs.1 build.1 bundle.1 cache.1 \
		changelog.1 coding-style.1 completion.1 config.1 dedupe.1 \
		deprecate.1 developers.1 disputes.1 docs.1 edit.1 explore.1 \
		faq.1 folders.1 help-search.1 help.1 index.1 init.1 install.1 \
		json.1 link.1 ls.1 npm.1 outdated.1 owner.1 pack.1 prefix.1 \
		prune.1 publish.1 rebuild.1 registry.1 removing-npm.1 \
		restart.1 root.1 run-script.1 scripts.1 search.1 semver.1 \
		shrinkwrap.1 star.1 start.1 stop.1 submodule.1 tag.1 test.1 \
		uninstall.1 unpublish.1 update.1 version.1 view.1 whoami.1
MAN3=		bin.3 bugs.3 commands.3 config.3 deprecate.3 docs.3 edit.3 \
		explore.3 help-search.3 init.3 install.3 link.3 load.3 ls.3 \
		npm.3 outdated.3 owner.3 pack.3 prefix.3 prune.3 publish.3 \
		rebuild.3 restart.3 root.3 run-script.3 search.3 shrinkwrap.3 \
		start.3 stop.3 submodule.3 tag.3 test.3 uninstall.3 \
		unpublish.3 update.3 version.3 view.3 whoami.3
MANPREFIX=	${PREFIX}/lib/node_modules/npm

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNODE_DEVEL}
RUN_DEPENDS+=	node-devel>=0.8.0:${PORTSDIR}/www/node-devel
.else
RUN_DEPENDS+=	node>=0.8.0:${PORTSDIR}/www/node
.endif

# maintainer section:
# require: bash, git, gmake, node

MS_DISTNAME=	${PORTNAME}-${MS_VERSION}
MS_TAGS=	${MS_WRKSRC}/tags
MS_VERSION=	`${CAT} ${MS_VERSIONFILE}`
MS_VERSIONFILE=	${MS_WRKSRC}/.version
MS_WRKSRC=	${WRKSRC}/tmp

GITHUB_PROJECT=	${PORTNAME}
GITHUB_TAGSURL=	https://github.com/isaacs/npm/tags
GITHUB_TARBALL=	https://github.com/${GITHUB_USER}/${GITHUB_PROJECT}/archive/${GITHUB_VERSION}.tar.gz
GITHUB_USER=	isaacs
GITHUB_VERSION=	v${MS_VERSION}

maketar: do-clean extract
	@${MKDIR} ${MS_WRKSRC}/
	@${FETCH_BINARY} ${FETCH_ARGS:C/A//} -o ${MS_WRKSRC}/tags ${GITHUB_TAGSURL}
	@${GREP} -o '/${GITHUB_USER}/${GITHUB_PROJECT}/archive/[^"]*\.tar\.gz' ${MS_WRKSRC}/tags | ${HEAD} -1 | ${CUT} -d/ -f5 | ${SED} 's|^v||; s|\.tar\.gz$$||' > ${MS_VERSIONFILE}
	@${ECHO_MSG} "*** Updating from ${PORTVERSION} to ${MS_VERSION} ..."
	@${FETCH_BINARY} ${FETCH_ARGS:C/A//} -o ${MS_WRKSRC}/${MS_DISTNAME}.tar.gz ${GITHUB_TARBALL}
	@${MKDIR} ${MS_WRKSRC}/${MS_DISTNAME}/
	@${TAR} -xf ${MS_WRKSRC}/${MS_DISTNAME}.tar.gz -C ${MS_WRKSRC}/${MS_DISTNAME}/ --strip-components 1
	@${SED} -i '' -e '/manRoot/ s|, "share"||' ${MS_WRKSRC}/${MS_DISTNAME}/lib/build.js ${MS_WRKSRC}/${MS_DISTNAME}/lib/unbuild.js
	@${SED} -i '' -e '1 s|#!/bin/bash|#!${LOCALBASE}/bin/bash|' ${MS_WRKSRC}/${MS_DISTNAME}/scripts/doc-build.sh
	@${GREP} -lr share/man ${MS_WRKSRC}/${MS_DISTNAME}/doc/ ${MS_WRKSRC}/${MS_DISTNAME}/scripts/ | ${XARGS} -I % ${SED} -i '' 's|share/man|man|g' %
	@cd ${MS_WRKSRC}/${MS_DISTNAME}/ && ${GMAKE}
	@${FIND} ${MS_WRKSRC}/${MS_DISTNAME}/ -type d -exec ${CHMOD} 755 '{}' \;
	@${FIND} ${MS_WRKSRC}/${MS_DISTNAME}/ -type f -exec ${CHMOD} 644 '{}' \;
	@cd ${MS_WRKSRC}/ && ${TAR} -Jcf ${MS_DISTNAME}.tar.xz ${MS_DISTNAME}/
	@${SED} -i '' -e '/^PORTVERSION=/ s|${PORTVERSION}|'${MS_VERSION}'|; /^PORTREVISION=/d' ${.CURDIR}/Makefile
	@${INSTALL} -m 644 ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}.tar.xz ${DISTDIR}/
	@cd ${.CURDIR}/ && ${MAKE} makesum

.include <bsd.port.mk>
