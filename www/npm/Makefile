# New ports collection makefile for:	npm
# Date created:		2011-12-18
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	npm
PORTVERSION=	1.1.45
CATEGORIES=	www
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Node package manager

OPTIONS_DEFINE=	NODE_DEVEL
NODE_DEVEL_DESC=Use www/node-devel instead of www/node

MAKE_JOBS_UNSAFE=	yes
NO_BUILD=	yes
USE_XZ=		yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNODE_DEVEL}
RUN_DEPENDS+=	${LOCALBASE}/bin/node:${PORTSDIR}/www/node-devel
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/node:${PORTSDIR}/www/node
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
	${SED} -i '' -e '/manRoot/ s|, "share"||' ${MS_WRKSRC}/${MS_DISTNAME}/lib/build.js ${MS_WRKSRC}/${MS_DISTNAME}/lib/unbuild.js
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
