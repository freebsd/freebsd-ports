PORTNAME=	zine-ssg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.2
CATEGORIES=	www

MAINTAINER=	dave@freedave.net
COMMENT=	Fast and Flexible Static Site Generator
WWW=		https://zine-ssg.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# This is needed to run `make test`.
TEST_DEPENDS=	git:devel/git

USES=		inotify zig:015

USE_GITHUB=	yes
GH_ACCOUNT=	kristoff-it
GH_PROJECT=	zine

CONFLICTS_INSTALL=	zine

PLIST_FILES=	bin/zine

.include <bsd.port.pre.mk>

post-patch:
.if defined(INOTIFY_PORT)
	${REINPLACE_CMD} -e 's|%INOTIFY_GUARD%||' ${WRKSRC}/build.zig
.else
	# comment out of builds for FreeBSD15+
	${REINPLACE_CMD} -e 's|%INOTIFY_GUARD%|// |' ${WRKSRC}/build.zig
.endif

# zine needs to test with a git repo which the ports build system goes out of
# its way to *not* use. So step 1 is to create the git repo... its just for the test
# Also we have to remove the -D... and --release... flags. zine is using "snapshot"
# testing and changing args breaks that.
do-test:
	cd ${BUILD_WRKSRC} && ${RM} -r .git && git init . && git add tests && git commit -m 'tests'
	cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD:N-D*:N--release=*:S/build/build test --summary all/}

.include <bsd.port.post.mk>
