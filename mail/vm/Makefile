# New ports collection makefile for: vm
# Date created: 	20 February 2002
# Whom:			olive
#
# $FreeBSD$
#

PORTNAME=	vm
PORTVERSION=	7.07
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.uni-mainz.de/pub/software/gnu/vm/ \
		ftp://tug.org/vm/ \
		ftp://psg.com/pub/vm/ \
		ftp://sunsite.cnlab-switch.ch/mirror/vm/ \
		http://www.interhack.net/projects/vm/ \
		ftp://ftp.uu.net/networking/mail/vm/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/VM/ \
		http://www.rge.com/pub/mail/vm/ \
		http://ftp.lip6.fr/pub/unix/mail/vm/ \
		ftp://ftp.surfnet.nl/pub/mail/vm/ \
		http://ftp.dmz.digex.net/pub/packages/mail/vm/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

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
	${INSTALL_DATA} ${WRKSRC}/*.el ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

.include <bsd.port.mk>
