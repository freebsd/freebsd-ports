PORTNAME=	opengist
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.0
PORTREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES+=	https://github.com/thomiceli/${PORTNAME}/releases/download/${DISTVERSIONFULL}/:webdist
DISTFILES+=	${PORTNAME}${DISTVERSION}-webdist.tar.gz:webdist
EXTRACT_ONLY=	${GO_DISTFILE}

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Self-hosted pastebin powered by Git, open-source alternative to Github Gist
WWW=		https://opengist.io/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:1.27+,modules

CGO_ENABLED=	0
GO_MODULE=	github.com/thomiceli/opengist
GO_LDFLAGS=	-X github.com/thomiceli/opengist/internal/config.OpengistVersion=${DISTVERSIONFULL}
GO_BUILDFLAGS=	-tags fs_embed
GO_TARGET=	.

USE_RC_SUBR=	opengist

GROUPS=		opengist
USERS=		opengist

post-extract:
	@if [ ! -d ${WRKSRC}/public/assets ]; then \
	    (${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${_DISTFILES:M*webdist*} --strip-components=1 -C ${WRKSRC}/public ${EXTRACT_AFTER_ARGS}) ;\
	fi

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
