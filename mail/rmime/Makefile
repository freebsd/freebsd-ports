# New ports collection makefile for:	rmime
# Date created:			28 July 2001
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	rmime
PORTVERSION=	1.2
CATEGORIES=	mail
MASTER_SITES=	http://www.cinti.net/~rmoody/rmime/ \
		${MASTER_SITE_LOCAL} \
		http://www.unixfreak.org/~dima/distfiles/
MASTER_SITE_SUBDIR=	dd
DISTNAME=	rmime.el
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	dd@FreeBSD.org
COMMENT=	Decode MIME messages inside Emacs (works with RMAIL, VM, and mh-e)

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs20
RUN_DEPENDS=	metamail:${PORTSDIR}/mail/metamail

NO_WRKSUBDIR=	yes
STRIP=		# empty

do-build:
	${CP} ${DISTDIR}/rmime.el ${WRKDIR}
	emacs -batch -f batch-byte-compile ${WRKDIR}/rmime.el

do-install:
	${INSTALL_DATA} ${WRKDIR}/rmime.el ${WRKDIR}/rmime.elc\
		${PREFIX}/share/emacs/site-lisp

.include <bsd.port.mk>
