# New ports collection makefile for:   eudc-emacs20
# Date created:        8 February 2001
# Whom:                ilya
#
# $FreeBSD$
#

PORTNAME=	eudc
PORTVERSION=	1.30b
PORTREVISION=	1
CATEGORIES=	net mail elisp
MASTER_SITES=	http://diwww.epfl.ch/~figueire/Software/eudc/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Emacs client to directory servers

BROKEN=		"Requires net/openldap12 which is no more. If you are adventurish, maybe you would like to take over the maintainership and make this port working with net/openldap21-client"

RUN_DEPENDS=	ldapsearch:${PORTSDIR}/net/openldap12

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

PLIST_SUB+=	EMACS_PORT_NAME=${EMACS_PORT_NAME} \
		INFODIR=${INFODIR:S/${PREFIX}\///}

INSTALL_TARGET=
lispdir=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/eudc

post-build:
	@(cd ${WRKSRC}; makeinfo --no-split eudc.texi)
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
