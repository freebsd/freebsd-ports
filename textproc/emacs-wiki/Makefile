# New ports collection makefile for:   emacs-wiki
# Date created:                March 09 2005
# Whom:                        Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	emacs-wiki
PORTVERSION=	2.69
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www.mwolson.org/static/dist/emacs-wiki/ \
		http://bsdchat.com/dist/dryice/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	Create and use hyperlinks and simple formatting in plain text files

WRKSRC=		${WRKDIR}/${PORTNAME}
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
