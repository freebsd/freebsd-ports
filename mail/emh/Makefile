# New ports collection makefile for:	emh (for emacs21)
# Date Created:		12 Mar 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	emh
PORTVERSION=	1.14.1
PORTREVISION=	4
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ring.aist.go.jp/pub/elisp/semi/semi-1.14-for-flim-1.14/ \
		http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/lemi/dist/semi/semi-1.14-for-flim-1.14/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	MIME extension of mh-e.el

BUILD_DEPENDS+=	${LOCALBASE}/share/semi/${SEMI_COOKIE}:${PORTSDIR}/editors/semi${DEPPORT_SUFFIX}
RUN_DEPENDS+=	${LOCALBASE}/share/semi/${SEMI_COOKIE}:${PORTSDIR}/editors/semi${DEPPORT_SUFFIX}

SEMI_TRUNK=	1.14
SEMI_COOKIE=	semi-${EMACS_PORT_NAME}-${SEMI_TRUNK}.FreeBSD-packages

USE_EMACS=	yes
.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} == xemacs21-mule
DEPPORT_SUFFIX=		-${EMACS_PORT_NAME}
ALL_TARGET=	package
INSTALL_TARGET=	install-package
EMH_LISPDIR=	${EMACS_LIBDIR}/site-packages/lisp/emh
XEMACS_ONLY=	""
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/mh-e/mh-e.el:${PORTSDIR}/editors/xemacs-packages
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/mh-e/mh-e.el:${PORTSDIR}/editors/xemacs-packages
.else
.if ${EMACS_PORT_NAME} == "emacs20"
DEPPORT_SUFFIX=		-${EMACS_PORT_NAME}
.else
DEPPORT_SUFFIX=		
.endif
ALL_TARGET=	elc
EMH_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/semi
MAKE_ARGS+=	LISPDIR=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
XEMACS_ONLY=	"@comment "
.endif

PLIST_SUB=	XEMACS_ONLY=${XEMACS_ONLY} \
		EMH_LISPDIR=${EMH_LISPDIR}

.include <bsd.port.post.mk>
