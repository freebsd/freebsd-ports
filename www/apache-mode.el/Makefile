# Created by: Max N. Boyarov <m.boyarov@bsd.by>
# $FreeBSD$

PORTNAME=	apache-mode.el
PORTVERSION=	2.0
CATEGORIES=	www elisp
MASTER_SITES=	http://ncd0.bsd.by/ports/distfiles/	\
		http://www.emacswiki.org/cgi-bin/wiki/download/
DISTNAME=	apache-mode.el
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	m.boyarov@bsd.by
COMMENT=	[X]Emacs major mode for editing Apache configuration files

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

NO_STAGE=	yes
do-install:
	${MKDIR} ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${EMACSLISPDIR}/${PORTNAME}
	${LN} -sf ${EMACSLISPDIR}/${PORTNAME} ${XEMACSLISPDIR}/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
