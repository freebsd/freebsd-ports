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

MAINTAINER=	max.n.boyarov@gmail.com
COMMENT=	Emacs major mode for editing Apache configuration files

LICENSE=	GPLv2

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	${EMACSLISPDIR}/apache-mode.el
EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp

do-install:
	${MKDIR} ${STAGEDIR}${EMACSLISPDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${EMACSLISPDIR}/${PORTNAME}

.include <bsd.port.mk>
