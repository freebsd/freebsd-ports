# $FreeBSD$

PORTNAME=	markdown-mode.el
PORTVERSION=	2.1
CATEGORIES=	textproc
MASTER_SITES=	http://jblevins.org/projects/markdown-mode/
DISTNAME=	markdown-mode.el
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Emacs/XEmacs major mode for editing Markdown-formatted text

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_EMACS=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/markdown-mode.el

do-install:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/markdown-mode.el

.include <bsd.port.mk>
