# New ports collection makefile for:	eldav, WebDAV for Emacs-MULE
# Date created:		2002-09-05
# Whom:			Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	eldav.el
PORTVERSION=	0.8.1
PORTEPOCH=	1
CATEGORIES=	www elisp
MASTER_SITES=	http://www.gohome.org/eldav/
DISTNAME=	eldav-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interface to WebDAV servers for Emacs

RUN_DEPENDS=	nd:${PORTSDIR}/www/nd

NO_BUILD=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
.for file in eldav.el vc-eldav.el
	${INSTALL_DATA} ${WRKSRC}/${file} ${EMACSLISPDIR}/
	${LN} -sf ${EMACSLISPDIR}/${file} ${XEMACSLISPDIR}/
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
