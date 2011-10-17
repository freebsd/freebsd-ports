# New ports collection makefile for:	muse
# Date created:				February 22 2006
# Whom:					Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	muse
PORTVERSION=	3.20
PORTREVISION=	3
CATEGORIES=	textproc elisp
MASTER_SITES=	http://download.gna.org/muse-el/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An authoring and publishing environment for Emacs

USE_EMACS=	yes
USE_GMAKE=	yes

INFO=		muse

LISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog ChangeLog.1 ChangeLog.2 ChangeLog.3 NEWS \
		README scripts COPYING
.endif

post-install:
	${MKDIR} ${LISPDIR}/contrib
.for i in *
	${CP} -R ${WRKSRC}/contrib/${i} ${LISPDIR}/contrib
.endfor

	${MKDIR} ${LISPDIR}/experimental
.for i in *
	${INSTALL_DATA} ${WRKSRC}/experimental/${i} ${LISPDIR}/experimental
.endfor

	${MKDIR} ${EXAMPLESDIR}
.for i in *
	${CP} -R ${WRKSRC}/examples/${i} ${EXAMPLESDIR}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${CP} -R ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} != "emacs23"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

.include <bsd.port.post.mk>
