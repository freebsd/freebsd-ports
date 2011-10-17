# New ports collection makefile for:   uim-el
# Date created:        24 December 2005
# Whom:                MANTANI Nobutaka <nobutaka@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	uim-el
PORTVERSION=	1.7.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	uim-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	Emacs lisp for uim input method library

PROJECTHOST=	uim
CONFLICTS?=	uim-el-xemacs21-mule-[0-9]* \
	uim-el-emacs22-[0-9]* \
	uim-el-emacs21-[0-9]*

RUN_DEPENDS=	uim-el-agent:${PORTSDIR}/textproc/uim

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	intltool
USE_GMAKE=	yes
USE_ICONV=	yes
USE_EMACS=	yes
GNU_CONFIGURE=	yes

BUILD_WRKSRC=	${WRKSRC}/emacs
INSTALL_WRKSRC=	${WRKSRC}/emacs

CONFIGURE_ARGS?=--enable-emacs --with-lispdir=${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}
CONFIGURE_ENV=	EMACS="${EMACS_CMD}" \
		LIBS="${LIBS} -L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

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
