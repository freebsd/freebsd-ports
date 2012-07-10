# New ports collection makefile for:	npm
# Date created:		2011-12-18
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	npm
PORTVERSION=	1.1.21
CATEGORIES=	www
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Node package manager

OPTIONS=	NODE_DEVEL "Use www/node-devel instead of www/node" off

NO_BUILD=	yes
USE_XZ=		yes

MAN1=		npm.1 npm-README.1 npm-adduser.1 npm-bin.1 npm-bugs.1 \
		npm-build.1 npm-bundle.1 npm-cache.1 npm-changelog.1 \
		npm-coding-style.1 npm-completion.1 npm-config.1 \
		npm-deprecate.1 npm-developers.1 npm-disputes.1 npm-docs.1 \
		npm-edit.1 npm-explore.1 npm-faq.1 npm-folders.1 \
		npm-help-search.1 npm-help.1 npm-index.1 npm-init.1 \
		npm-install.1 npm-json.1 npm-link.1 npm-list.1 npm-outdated.1 \
		npm-owner.1 npm-pack.1 npm-prefix.1 npm-prune.1 npm-publish.1 \
		npm-rebuild.1 npm-registry.1 npm-removing-npm.1 npm-restart.1 \
		npm-root.1 npm-run-script.1 npm-scripts.1 npm-search.1 \
		npm-semver.1 npm-shrinkwrap.1 npm-star.1 npm-start.1 \
		npm-stop.1 npm-submodule.1 npm-tag.1 npm-test.1 \
		npm-uninstall.1 npm-unpublish.1 npm-update.1 npm-version.1 \
		npm-view.1 npm-whoami.1
MAN3=		npm.3 npm-bin.3 npm-bugs.3 npm-commands.3 npm-config.3 \
		npm-deprecate.3 npm-docs.3 npm-edit.3 npm-explore.3 \
		npm-help-search.3 npm-init.3 npm-install.3 npm-link.3 \
		npm-load.3 npm-ls.3 npm-outdated.3 npm-owner.3 npm-pack.3 \
		npm-prefix.3 npm-prune.3 npm-publish.3 npm-rebuild.3 \
		npm-restart.3 npm-root.3 npm-run-script.3 npm-search.3 \
		npm-shrinkwrap.3 npm-start.3 npm-stop.3 npm-submodule.3 \
		npm-tag.3 npm-test.3 npm-uninstall.3 npm-unpublish.3 \
		npm-update.3 npm-version.3 npm-view.3 npm-whoami.3

.include <bsd.port.options.mk>

.if !defined(WITH_NODE_DEVEL)
RUN_DEPENDS=	${LOCALBASE}/bin/node:${PORTSDIR}/www/node
.else
RUN_DEPENDS=	${LOCALBASE}/bin/node:${PORTSDIR}/www/node-devel
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
GITHUB_TARBALL=	https://github.com/${GITHUB_USER}/${GITHUB_PROJECT}/tarball/${GITHUB_VERSION}
GITHUB_USER=	isaacs
GITHUB_VERSION=	v${MS_VERSION}

maketar: do-clean extract
	${MKDIR} ${MS_WRKSRC}/
	${FETCH_BINARY} ${FETCH_ARGS:C/A//} -o ${MS_WRKSRC}/tags ${GITHUB_TAGSURL}
	${GREP} -o '/${GITHUB_USER}/${GITHUB_PROJECT}/tarball/[^"]*' ${MS_WRKSRC}/tags | ${HEAD} -1 | ${CUT} -d/ -f5 | ${SED} 's|^v||' > ${MS_VERSIONFILE}
	${ECHO_MSG} "*** Updating from ${PORTVERSION} to ${MS_VERSION} ..."
	${FETCH_BINARY} ${FETCH_ARGS:C/A//} -o ${MS_WRKSRC}/${MS_DISTNAME}.tar.gz ${GITHUB_TARBALL}
	${MKDIR} ${MS_WRKSRC}/${MS_DISTNAME}/
	${TAR} -xf ${MS_WRKSRC}/${MS_DISTNAME}.tar.gz -C ${MS_WRKSRC}/${MS_DISTNAME}/ --strip-components 1
	${REINPLACE_CMD} -e '/manRoot/ s|, "share"||' ${MS_WRKSRC}/${MS_DISTNAME}/lib/build.js ${MS_WRKSRC}/${MS_DISTNAME}/lib/unbuild.js
	${SED} -i '' -e '1 s|#!/bin/bash|#!${LOCALBASE}/bin/bash|' ${MS_WRKSRC}/${MS_DISTNAME}/scripts/doc-build.sh
	${GREP} -lr share/man ${MS_WRKSRC}/${MS_DISTNAME}/doc/ ${MS_WRKSRC}/${MS_DISTNAME}/scripts/ | ${XARGS} -I % ${SED} -i '' 's|share/man|man|g' %
	cd ${MS_WRKSRC}/${MS_DISTNAME}/ && ${GMAKE}
	${FIND} ${MS_WRKSRC}/${MS_DISTNAME}/ -type d -exec ${CHMOD} 755 '{}' \;
	${FIND} ${MS_WRKSRC}/${MS_DISTNAME}/ -type f -exec ${CHMOD} 644 '{}' \;
	cd ${MS_WRKSRC}/ && ${TAR} -Jcf ${MS_DISTNAME}.tar.xz ${MS_DISTNAME}/
	${SED} -i '' -e '/^PORTVERSION=/ s|${PORTVERSION}|'${MS_VERSION}'|; /^PORTREVISION=/d' ${.CURDIR}/Makefile
	${INSTALL} -m 644 ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}.tar.xz ${DISTDIR}/
	cd ${.CURDIR}/ && ${MAKE} makesum

.include <bsd.port.mk>
