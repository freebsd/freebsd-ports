# New ports collection makefile for:	man.el with I18N
# Version required:	1.1
# Date created:		10 September 1998
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id$
#

DISTNAME=	i18n-man-1.1
CATEGORIES=	misc elisp
MASTER_SITES=	ftp://jaz.jp.freebsd.org/pub/FreeBSD-jp/man-jp/ \
		ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

RUN_DEPENDS=	jman:${PORTSDIR}/japanese/man

NO_WRKDIR=	yes
NO_EXTRACT=	yes
NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp

do-install:
	@${MKDIR} ${ELISPDIR};
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTFILES} -C ${ELISPDIR}
	@files=`${EXTRACT_CMD} tzf ${DISTDIR}/${DISTFILES}`; \
	for f in $${files}; do \
		chown ${SHAREOWN}:${SHAREGRP} ${ELISPDIR}/$${f}; \
		chmod ${SHAREMODE} ${ELISPDIR}/$${f}; \
	done

.include <bsd.port.mk>
