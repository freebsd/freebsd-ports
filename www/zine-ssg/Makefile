PORTNAME=	zine-ssg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
CATEGORIES=	www

MAINTAINER=	dave@freedave.net
COMMENT=	Fast and Flexible Static Site Generator
WWW=		https://zine-ssg.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_FreeBSD_14=	fails to build on FreeBSD 14

# This is needed to run `make test`.
TEST_DEPENDS=	git:devel/git

USES=		inotify zig

USE_GITHUB=	yes
GH_ACCOUNT=	kristoff-it
GH_PROJECT=	zine

CONFLICTS_INSTALL=	zine

PLIST_FILES=	bin/zine

.include <bsd.port.pre.mk>

PATCH_WRKSRC=    ${WRKDIR}

# zine uses snapshot testing that leans heavily on git.
# The build is in fact going to delete some files to ensure they are recreated the same.
# It counts on git detecting no change. That means we must tar off the tests after
# patching to make a git commit IFF tests are run. But we want the deleted files to be
# checked as well. Because git checks file mode, COPYTREE_SHARE can't be used.
post-patch:
	${REINPLACE_CMD} -e 's:%%DISTVERSION%%:${DISTVERSION}:' ${WRKSRC}/build.zig
.if defined(INOTIFY_PORT)
	${REINPLACE_CMD} -e 's|%INOTIFY_GUARD%||' ${WRKSRC}/build.zig
.else
	# comment out of builds for FreeBSD15+
	${REINPLACE_CMD} -e 's|%INOTIFY_GUARD%|// |' ${WRKSRC}/build.zig
.endif
	${MKDIR} ${WRKDIR}/preserve
	cd ${WRKSRC} && ${TAR} cf - tests | (cd ${WRKDIR}/preserve && ${TAR} xf -)

# zine needs to test with a git repo which the ports build system goes out of
# its way to *not* use. So step 1 is to create the git repo... its just for the test
# Also we have to remove the -D... and --release... flags. zine is using "snapshot"
# testing and changing args breaks that.
do-test:
	cd ${WRKDIR}/preserve && ${RM} -r .git && git init . && git add tests && git commit -m 'tests'
	${RM} -r ${BUILD_WRKSRC}/.git
	${MV} ${WRKDIR}/preserve/.git ${BUILD_WRKSRC}
	cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD:N-D*:N--release=*:S/build/build test --summary all/}

.include <bsd.port.post.mk>
