# New ports collection makefile for:	man.el with I18N
# Version required:	1.1
# Date created:		10 September 1998
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.3 1998/12/16 11:33:28 flathill Exp $
#

DISTNAME=	i18n-man-1.1
CATEGORIES=	misc elisp
MASTER_SITES=	ftp://jaz.jp.freebsd.org/pub/FreeBSD-jp/man-jp/ \
		ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

RUN_DEPENDS=	jman:${PORTSDIR}/japanese/man

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

ELISPDIR=	${PREFIX}/share/emacs/site-lisp

do-install:
	@${MKDIR} ${ELISPDIR}
	@cd ${WRKSRC}; \
	${INSTALL_DATA} `${TAR} tzf ${DISTDIR}/${DISTFILES}` ${ELISPDIR}

.include <bsd.port.mk>
