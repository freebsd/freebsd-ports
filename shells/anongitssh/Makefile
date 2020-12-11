# $FreeBSD$

PORTNAME=	anongitssh
PORTVERSION=	0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	shells

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Restricted shell for git-upload-pack over SSH

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	hrs-allbsd
MAKE_ARGS=	MK_INSTALL_AS_USER="yes" BINMODE=0555

README_URL?=		https://git.FreeBSD.org/
REPODIR_PREFIX?=	/home/git
ANONGIT_USER?=		anongit
CONTACT?=		git-admin@FreeBSD.org
GITUPLOADPACK_PATH?=	/usr/local/bin/git-upload-pack
.for D in README_URL REPODIR_PREFIX ANONGIT_USER CONTACT GITUPLOADPACK_PATH
MAKE_ARGS+=	${D}=\"${$D}\"
.endfor

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
