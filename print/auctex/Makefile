# New ports collection makefile for:	auctex
# Date created:				21 November 1999
# Whom:					Martin Kammerhofer
#
# $FreeBSD$
#

PORTNAME=		auctex
PORTVERSION=		11.51
PORTREVISION=		1
CATEGORIES=		print elisp
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Integrated environment for writing LaTeX using GNU Emacs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${LISPDIR} \
		--with-auto-dir=${PREFIX}/${LISPDIR}/auctex/auto
EMACS_PORT_NAME?=	emacs21
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}
ALL_TARGET=	all contrib
INSTALL_TARGET=	install install-contrib

PLIST_SUB+=	LISPDIR=${LISPDIR}
INFO=		auctex

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
