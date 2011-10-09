# New ports collection makefile for:   emacs-wiki
# Date created:                March 09 2005
# Whom:                        Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	emacs-wiki
PORTVERSION=	2.72
PORTREVISION=	4
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www.mwolson.org/static/dist/emacs-wiki/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	dryice@dryice.name
COMMENT=	Create and use hyperlinks and simple formatting in plain text files

DEPRECATED=	Depends on textproc/htmlize.el, which is DEPRECATED
EXPIRATION_DATE=	2011-10-31

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

RUN_DEPENDS+=	${PREFIX}/${EMACS_SITE_LISPDIR}/xml-parse.el:${PORTSDIR}/textproc/xml-parse.el
RUN_DEPENDS+=	${PREFIX}/${EMACS_SITE_LISPDIR}/htmlize.el:${PORTSDIR}/textproc/htmlize.el

.if defined(WITH_CONTRIB)
PLIST_SUB+=	CONTRIB=""
.else
PLIST_SUB+=	CONTRIB="@comment "
.endif

INFO=		emacs-wiki
LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

pre-everything::
.if !defined(WITH_CONTRIB)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may want to build with WITH_CONTRIB=yes"
	@${ECHO_MSG} "to install some extra packages. Note this may"
	@${ECHO_MSG} "shadow the versions you already installed elsewhere."
	@${ECHO_MSG} ""
.endif

do-build:
	cd ${WRKSRC}; makeinfo --no-split emacs-wiki.texi

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/emacs-wiki.info ${PREFIX}/info
.if defined(WITH_CONTRIB)
	${MKDIR} ${LISPDIR}/contrib
.for i in *.el
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${LISPDIR}/contrib
.endfor
.endif

.include <bsd.port.mk>
