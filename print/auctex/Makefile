# New ports collection makefile for:	auctex
# Date created:				21 November 1999
# Whom:					Martin Kammerhofer
#
# $FreeBSD$
#

PORTNAME=		auctex
PORTVERSION=		11.14
CATEGORIES=		print elisp
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=		hrs@FreeBSD.org
COMMENT=	Integrated environment for writing LaTeX using GNU Emacs

EMACS_PORT_NAME?=	emacs21
EMACS_NO_RUN_DEPENDS=	yes
LISPDIR=	${EMACS_SITE_LISPDIR}
ALL_TARGET=	all contrib
INSTALL_TARGET=	install install-contrib install-info
MAKE_ARGS+=	lispdir=${PREFIX}/${LISPDIR}
PLIST_SUB+=	LISPDIR=${LISPDIR}
USE_REINPLACE=	yes
INFO=		auctex

post-patch:
	${REINPLACE_CMD} -e 's?%%PREFIX%%?${PREFIX}?g' ${WRKSRC}/tex.el

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in CHANGES INSTALLATION README
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
