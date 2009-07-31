# New ports collection makefile for: vm
# Date created: 	20 February 2002
# Whom:			olive
#
# $FreeBSD$
#

PORTNAME=	vm
PORTVERSION=	7.19
PORTREVISION=	2
CATEGORIES=	mail elisp
MASTER_SITES=	http://www.seanet.com/~kylemonger/vm/ \
		ftp://ftp.uni-mainz.de/pub/software/gnu/vm/ \
		ftp://tug.org/vm/ \
		ftp://psg.com/pub/vm/ \
		ftp://sunsite.cnlab-switch.ch/mirror/vm/ \
		ftp://ftp.uu.net/networking/mail/vm/ \
		http://www.interhack.net/projects/vm/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/VM/ \
		http://ftp.lip6.fr/pub/unix/mail/vm/ \
		ftp://ftp.surfnet.nl/pub/mail/vm/ \
		http://ftp.gwdg.de/pub/gnu2/vm/ \
		http://ftp.vim.org/pub/mail/vm/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mail reader running inside Emacs or XEmacs

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21
MAKE_ARGS=	prefix=${PREFIX} \
		INFODIR=${PREFIX}/info \
		LISPDIR=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME} \
		PIXMAPDIR=${PREFIX}/${EMACS_LIBDIR_WITH_VER}/etc/vm

INFO=		vm

.include <bsd.port.mk>
