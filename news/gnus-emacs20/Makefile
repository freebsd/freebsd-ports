# New ports collection makefile for:   gnus-emacs20
# Date created:        29 January 2001
# Whom:                ilya
#
# $FreeBSD$
#

PORTNAME=	gnus
PORTVERSION=	5.8.8
CATEGORIES=	news mail elisp
MASTER_SITES=	ftp://ftp.gnus.org/pub/gnus/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ilya@martynov.org

HAS_CONFIGURE=	yes

EMACS_PORT_NAME?=emacs20

CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}/gnus \
		--infodir=${INFODIR}

INFODIR=	${PREFIX}/info

PORTDOCDIR=	share/doc/gnus-${EMACS_PORT_NAME}
DOCS=		ChangeLog GNUS-NEWS README

PLIST_SUB=	EMACS_PORT_NAME=${EMACS_PORT_NAME} \
		INFODIR=${INFODIR:S/${PREFIX}\///} \
		EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${PORTDOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${PORTDOCDIR}
.endfor
.endif

.include <bsd.port.mk>
