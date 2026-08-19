PORTNAME=	opengist
PORTVERSION=	1.15.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	www textproc

# prebuilt frontend assets published upstream (see upstream PR #768)
MASTER_SITES+=	https://github.com/thomiceli/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/:webdist
DISTFILES+=	${PORTNAME}${DISTVERSION}-webdist.tar.gz:webdist

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Self-hosted pastebin powered by Git, open-source alternative to Github Gist
WWW=		https://opengist.io/

LICENSE=	AGPLv3

BROKEN_i386=	fails to build
ONLY_FOR_ARCHS=	aarch64 amd64

RUN_DEPENDS=	git:devel/git

USES=		go:1.26+,modules

GO_MODULE=	github.com/thomiceli/opengist
GO_ENV+=	GOTOOLCHAIN=local+path
GO_TARGET=	.
GO_BUILDFLAGS=	-tags fs_embed \
		-ldflags="-X github.com/thomiceli/opengist/internal/config.OpengistVersion=v${DISTVERSION}"

USE_RC_SUBR=	opengist

GROUPS=		opengist
USERS=		opengist

# The go:modules source zip extracts to WRKSRC; unpack prebuilt web assets
# there.  The tarball wraps everything in a top-level opengist-webdist/
# directory, so strip it to land .vite/ and assets/ directly under public/.
post-extract:
	@${TAR} -xzf ${_DISTDIR}/${PORTNAME}${DISTVERSION}-webdist.tar.gz \
		--strip-components=1 -C ${WRKSRC}/public

post-patch:
	@${REINPLACE_CMD} -e 's|opengist.db|file:/var/db/${PORTNAME}/opengist.db|g' \
		${WRKSRC}/config.yml

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/config.yml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.yml.sample
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}

.include <bsd.port.mk>
