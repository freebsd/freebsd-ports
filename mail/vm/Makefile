# New ports collection makefile for: vm
# Date created: 	20 February 2002
# Whom:			olive
#
# $FreeBSD$
#

PORTNAME=	vm
PORTVERSION=	7.01
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.uni-mainz.de/pub/software/gnu/vm/ \
		ftp://tug.org/vm/ \
		ftp://psg.com/pub/vm/ \
		ftp://sunsite.cnlab-switch.ch/mirror/vm/ \
		http://www.interhack.net/projects/vm/ \
		ftp://ftp.uu.net/networking/mail/vm/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}

MAINTAINER=	olive@oban.frmug.org

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

EMACS_PORT_NAME?=	emacs21
MAKE_ARGS=	prefix=${PREFIX} \
		INFODIR=${PREFIX}/info \
		LISPDIR=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME} \
		PIXMAPDIR=${PREFIX}/${EMACS_LIBDIR_WITH_VER}/etc/vm

post-install:
.for info in vm.info
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
