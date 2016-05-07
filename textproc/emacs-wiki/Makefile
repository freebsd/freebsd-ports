# Created by: Dryice Liu <dryice@liu.com.cn>
# $FreeBSD$

PORTNAME=	emacs-wiki
PORTVERSION=	2.72
PORTREVISION=	7
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www.mwolson.org/static/dist/emacs-wiki/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	Create and use hyperlinks and simple formatting in plain text files

USES=		makeinfo
USE_EMACS=	yes

OPTIONS_DEFINE=	CONTRIB
CONTRIB_DESC=	Install extra packages. This can shadow versions already there.
OPTIONS_SUB=	yes

RUN_DEPENDS+=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/xml-parse.el:textproc/xml-parse.el
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/htmlize.el:textproc/htmlize.el

INFO=		emacs-wiki
LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC}; makeinfo --no-split emacs-wiki.texi

do-install:
	${MKDIR} ${STAGEDIR}${LISPDIR}
.for i in *.el
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/emacs-wiki.info ${STAGEDIR}${PREFIX}/info
.if ${PORT_OPTIONS:MCONTRIB}
	${MKDIR} ${STAGEDIR}${LISPDIR}/contrib
.for i in *.el
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${STAGEDIR}${LISPDIR}/contrib
.endfor
.endif

.include <bsd.port.mk>
