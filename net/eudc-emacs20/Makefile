# New ports collection makefile for:   eudc-emacs20
# Date created:        8 February 2001
# Whom:                ilya
#
# $FreeBSD$
#

PORTNAME=	eudc
PORTVERSION=	1.30b
CATEGORIES=	net mail elisp
MASTER_SITES=	http://lspwww.epfl.ch/~figueire/Software/eudc/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	ldapsearch:${PORTSDIR}/net/openldap

EMACS_PORT_NAME?=emacs20

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

INFODIR=	${PREFIX}/info

PORTDOCDIR=	share/doc/${PORTNAME}-${EMACS_PORT_NAME}
DOCS=		COPYRIGHT ChangeLog INSTALL NEWS README
SOURCES=	eudc-autoloads.el eudc-bob.el eudc-export.el \
		eudc-hotlist.el eudc-vars.el eudc.el \
		eudcb-bbdb.el eudcb-ldap.el eudcb-ph.el ldap.el
ELCS=		${SOURCES:S/.el/.elc/g}
INFOS=		eudc.info

PLIST_SUB=	EMACS_PORT_NAME=${EMACS_PORT_NAME} \
		INFODIR=${INFODIR:S/${PREFIX}\///} \
		EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

INSTALL_TARGET=
lispdir=	${PREFIX}/${EMACS_SITE_LISPDIR}/eudc
post-install:
	${MKDIR} ${lispdir};
.for i in ${SOURCES} ${ELCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${lispdir}
.endfor
.for i in ${INFOS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${INFODIR}
	install-info ${INFODIR}/eudc.info ${INFODIR}/dir
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${PORTDOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${PORTDOCDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
