# Created by: Akinori MUSHA aka knu <knu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	peco
PORTVERSION=	0.4.4
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/knu

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Simplistic interactive filtering tool

LICENSE=	MIT

USES=		go

WRKSRC_SUBDIR=	${GO_PKG_SUBDIR}
WRKSRC_GITDIR=	${WRKSRC:S|/${WRKSRC_SUBDIR}$$||}
GO_PKG_GITURL=	https://github.com/${PORTNAME}/${PORTNAME}
GO_PKG_SUBDIR=	cmd/peco
GO_PKGNAME=	${GO_PKG_GITURL:S|^https://||}/${GO_PKG_SUBDIR}
PLIST_FILES=	bin/peco
UPLOAD_FILE=	${_DISTDIR:S|/$||}/${DISTFILES:Mpeco-*.tar.gz}

post-extract:
	@${MKDIR} ${GO_WRKSRC:H:H:H}
	@${LN} -sf ${WRKSRC:H:H} ${GO_WRKSRC:H:H}

maintainer-fetch:
	@${MAKE} clean
	@${MKDIR} ${WRKSRC_GITDIR}
	@git clone ${GO_PKG_GITURL} \
		--branch v${DISTVERSION} --depth 1 ${WRKSRC_GITDIR}
	@cd ${WRKSRC_GITDIR} && glide install
	@${TAR} zcf ${UPLOAD_FILE} \
		-C ${WRKSRC_GITDIR}/.. --exclude .git ${DISTNAME}
	@${MAKE} makesum
	@${MAKE} clean

${UPLOAD_FILE}: maintainer-fetch

maintainer-distfile: ${UPLOAD_FILE}
	@rsync -aP ${UPLOAD_FILE} freefall.freebsd.org:public_distfiles/

.include <bsd.port.mk>
