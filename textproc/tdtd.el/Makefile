# New ports collection makefile for:	tdtd.el
# Date created:		15 September 2000
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	tdtd.el
PORTVERSION=	0.7.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.menteith.com/tdtd/data/
DISTNAME=	tdtd071
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An emacs major mode for editing SGML and XML DTDs

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs20

EMACS_NO_BUILD_DEPENDS=	YES

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_ZIP=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
DOCDIR=		${PREFIX}/share/doc

do-install:
	${MKDIR} ${ELISPDIR}
	${MKDIR} ${DOCDIR}/${PORTNAME}
	@(cd ${WRKSRC} && \
		${INSTALL_DATA} tdtd.el tdtd-font.el ${ELISPDIR} && \
		${INSTALL_DATA} TODO changelog.txt dot_emacs readme.txt tutorial.txt ${DOCDIR}/${PORTNAME} \
	)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
