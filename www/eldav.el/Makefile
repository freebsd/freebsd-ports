# New ports collection makefile for:	eldav, WebDAV for Emacs-MULE
# Date created:		2002-09-05
# Whom:			Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	eldav.el
PORTVERSION=	1.17
CATEGORIES=	www elisp
MASTER_SITES=	http://www.gohome.org/eldav/
DISTNAME=	eldav.el
EXTRACT_SUFX=	.gz
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de

RUN_DEPENDS=	nd:${PORTSDIR}/www/nd

EXTRACT_AFTER_ARGS=	| ${CAT} >${WRKDIR}/${DISTNAME}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${EMACSLISPDIR}/${DISTNAME}
	${MKDIR} ${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/${DISTNAME} ${XEMACSLISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
