# New ports collection makefile for:   emacs-w3m
# Date Created:			24 Mar 2001
# Whom:				MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	emacs-w3m
PORTVERSION=	0.2.126
CATEGORIES=	www elisp
MASTER_SITES=	http://namazu.org/~tsuchiya/emacs-w3m/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	w3m_el-${PORTVERSION}

MAINTAINER=	nobutaka@nobutaka.com

EMACS_PORT_NAME?=	emacs20
.if (${EMACS_PORT_NAME} == "emacs20")
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD}
.endif
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
CONFIGURE_ARGS=	--with-xemacs=${EMACS_CMD}
EMACS_PACKAGESDIR=	lib/xemacs/site-packages
MANIFEST=		MANIFEST.w3m
INSTALL_TARGET=		install-package
.endif

USE_AUTOCONF=	yes
ALL_TARGET=	default

PLIST_SUB+=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}

DOCS=		README
DOCS_JA=	README.ja TIPS.ja

DOCSDIR=	${PREFIX}/share/doc/emacs-w3m
DOCSDIR_JA=	${PREFIX}/share/doc/ja/emacs-w3m

pre-build:
.if defined(EMACS_PACKAGESDIR)
	@${CP} ${FILESDIR}/_pkg.el ${WRKSRC}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR_JA}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR_JA}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
