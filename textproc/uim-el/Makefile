# New ports collection makefile for:   uim-el
# Date created:        24 December 2005
# Whom:                MANTANI Nobutaka <nobutaka@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	uim-el
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://uim.freedesktop.org/releases/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	uim-${PORTVERSION}

MAINTAINER=	nobutaka@freebsd.org
COMMENT?=	Emacs lisp for uim input method library

CONFLICTS?=	uim-el-xemacs21-mule-[0-9]*

RUN_DEPENDS=	uim-el-agent:${PORTSDIR}/textproc/uim

USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_EMACS=	yes
GNU_CONFIGURE=	yes

EMACS_PORT_NAME?=	emacs21
BUILD_WRKSRC=	${WRKSRC}/emacs
INSTALL_WRKSRC=	${WRKSRC}/emacs

CONFIGURE_ARGS?=--enable-emacs --with-lispdir=${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}
CONFIGURE_ENV=	EMACS=${EMACS_CMD}

DOCSDIR_JA=	${PREFIX}/share/doc/ja/uim-el
PLIST_SUB+=	DOCSDIR_JA="${DOCSDIR_JA:S,^${PREFIX}/,,}"

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR_JA}
	${INSTALL_DATA} ${WRKSRC}/emacs/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/emacs/README.ja ${DOCSDIR_JA}/README.ja
.endif

.include <bsd.port.mk>
