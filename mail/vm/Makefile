# New ports collection makefile for: vm
# Date created: 	20 February 2002
# Whom:			olive
#
# $FreeBSD$
#

PORTNAME=	vm
PORTVERSION=	7.17
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.uni-mainz.de/pub/software/gnu/vm/ \
		ftp://tug.org/vm/ \
		ftp://psg.com/pub/vm/ \
		ftp://sunsite.cnlab-switch.ch/mirror/vm/ \
		ftp://ftp.uu.net/networking/mail/vm/ \
		http://www.interhack.net/projects/vm/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/VM/ \
		http://www.rge.com/pub/mail/vm/ \
		http://ftp.lip6.fr/pub/unix/mail/vm/ \
		ftp://ftp.surfnet.nl/pub/mail/vm/ \
		http://ftp.algx.net/pub/packages/mail/vm/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	olive@oban.frmug.org
COMMENT=	A mail reader running inside Emacs or XEmacs

EMACS_PORT_NAME?=	emacs21
MAKE_ARGS=	prefix=${PREFIX} \
		INFODIR=${PREFIX}/info \
		LISPDIR=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME} \
		PIXMAPDIR=${PREFIX}/${EMACS_LIBDIR_WITH_VER}/etc/vm

post-install:
	install-info ${PREFIX}/info/vm.info ${PREFIX}/info/dir

.include <bsd.port.mk>
