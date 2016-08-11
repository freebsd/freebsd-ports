# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	npm
PORTVERSION=	3.9.2
CATEGORIES=	www
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Node package manager

LICENSE=	MIT

RUN_DEPENDS=	gmake:devel/gmake \
		node>=0.8.0:www/node

CONFLICTS_INSTALL=	npm2-[0-9]*

MAKE_ARGS=	npm_config_prefix=${STAGEDIR}${PREFIX}
MANPREFIX=	${PREFIX}/lib/node_modules/npm
NO_ARCH=	yes
NO_BUILD=	yes
REINPLACE_ARGS=	-i ''
USES=		cpe python:2 shebangfix tar:xz

CPE_VENDOR=	npmjs
CPE_PRODUCT=	node_packaged_modules

SHEBANG_FILES=	lib/utils/completion.sh \
		node_modules/node-gyp/test/docker.sh \
		node_modules/request/node_modules/node-uuid/benchmark/bench.sh \
		scripts/clean-old.sh \
		scripts/release.sh \
		scripts/relocate.sh

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
# Workaround for kernel bug 178881
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-bug-178881
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|node cli.js|& --cache ${WRKDIR}/.cache|' ${WRKSRC}/Makefile
	@${ECHO_CMD} 'MANPATH ${PREFIX}/lib/node_modules/npm/man' > ${WRKDIR}/npm.conf
	@${REINPLACE_CMD} -e 's|exec python|exec ${PYTHON_CMD}|' ${WRKSRC}/node_modules/node-gyp/gyp/gyp

post-install:
	${INSTALL_DATA} ${WRKDIR}/npm.conf ${STAGEDIR}${PREFIX}/etc/man.d/npm.conf

# maintainer section:
# require: bash, git, gmake, perl, node

MS_DISTNAME=	${PORTNAME}-${MS_VERSION}
MS_PLIST=	${WRKDIR}/.ms-pkg-plist
MS_RELEASES=	${MS_WRKSRC}/releases
MS_VERSION=	`${CAT} ${MS_VERSIONFILE}`
MS_VERSIONFILE=	${MS_WRKSRC}/.version
MS_WRKSRC=	${WRKSRC}/tmp

GITHUB_PROJECT=	${PORTNAME}
GITHUB_RELEASES=https://github.com/${GITHUB_USER}/${GITHUB_PROJECT}/releases/latest
GITHUB_TARBALL=	https://github.com/${GITHUB_USER}/${GITHUB_PROJECT}/archive/${GITHUB_VERSION}.tar.gz
GITHUB_USER=	${PORTNAME}
GITHUB_VERSION=	v${MS_VERSION}

genplist: do-clean stage
	@${MAKE_CMD} makeplist > ${MS_PLIST}
	@${SED} -i '' '1 d; /^lib\/node_modules\/npm\/bin\/node-gyp-bin\/node-gyp$$/ s|^|@(,,755) |' ${MS_PLIST}
	@${INSTALL} -m 600 ${MS_PLIST} ${PLIST}

maketar: do-clean
	@${MKDIR} ${MS_WRKSRC}/
	@${FETCH_BINARY} ${FETCH_ARGS:C/A//} -o ${MS_RELEASES} ${GITHUB_RELEASES}
	@${GREP} -o '/${GITHUB_USER}/${GITHUB_PROJECT}/archive/[^"]*\.tar\.gz' ${MS_RELEASES} | ${HEAD} -1 | ${CUT} -d/ -f5 | ${SED} 's|^v||; s|\.tar\.gz$$||' > ${MS_VERSIONFILE}
	@${ECHO_MSG} "*** Updating from ${PORTVERSION} to ${MS_VERSION} ..."
	@${FETCH_BINARY} ${FETCH_ARGS:C/A//} -o ${MS_WRKSRC}/${MS_DISTNAME}.tar.gz ${GITHUB_TARBALL}
	@${MKDIR} ${MS_WRKSRC}/${MS_DISTNAME}/
	@${TAR} -xf ${MS_WRKSRC}/${MS_DISTNAME}.tar.gz -C ${MS_WRKSRC}/${MS_DISTNAME}/ --strip-components 1
	@${REINPLACE_CMD} -e 's|${MAKE}|${GMAKE}|g; /^install: / s| docclean||' ${MS_WRKSRC}/${MS_DISTNAME}/Makefile
	@${REINPLACE_CMD} -e 's| && ${MAKE} -j8 doc||' ${MS_WRKSRC}/${MS_DISTNAME}/package.json
	@${REINPLACE_CMD} -e 's|linkBins, linkMans|linkBins|; /manRoot/ s|, "share"||' ${MS_WRKSRC}/${MS_DISTNAME}/lib/build.js ${MS_WRKSRC}/${MS_DISTNAME}/lib/unbuild.js
	@${REINPLACE_CMD} -e '1 s|#!/bin/bash|#!${LOCALBASE}/bin/bash|; s|${MAKE}|${GMAKE}|g; s|perl -pi|perl -p|' ${MS_WRKSRC}/${MS_DISTNAME}/scripts/doc-build.sh
	@${GREP} -lr share/man ${MS_WRKSRC}/${MS_DISTNAME}/doc/ ${MS_WRKSRC}/${MS_DISTNAME}/scripts/ | ${XARGS} -I % ${REINPLACE_CMD} 's|share/man|man|g' %
	@cd ${MS_WRKSRC}/${MS_DISTNAME}/ && ${GMAKE} docclean markedclean all html/doc/misc/npm-index.html
	@${FIND} ${MS_WRKSRC}/${MS_DISTNAME}/ -type d -exec ${CHMOD} 755 '{}' \;
	@${FIND} ${MS_WRKSRC}/${MS_DISTNAME}/ -type f -exec ${CHMOD} 644 '{}' \;
	@${FIND} ${MS_WRKSRC}/${MS_DISTNAME}/ -type f -name '*.sh' -exec ${CHMOD} 755 '{}' \;
	@cd ${MS_WRKSRC}/ && ${TAR} -Jcf ${MS_DISTNAME}.tar.xz ${MS_DISTNAME}/
	@${REINPLACE_CMD} -e '/^PORTVERSION=/ s|${PORTVERSION}|'${MS_VERSION}'|; /^PORTREVISION=/d' ${.CURDIR}/Makefile
	@sudo ${INSTALL} -m 644 ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}.tar.xz ${DISTDIR}/
	@cd ${.CURDIR}/ && ${MAKE_CMD} makesum

.include <bsd.port.post.mk>
