# New ports collection makefile for:	man.el with I18N
# Version required:	1.1
# Date created:		10 September 1998
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	i18n-man-1.1
CATEGORIES=	misc elisp
MASTER_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/ \
		${MASTER_SITE_PORTS_JP}

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
