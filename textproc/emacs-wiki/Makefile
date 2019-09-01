# Created by: Dryice Liu <dryice@liu.com.cn>
# $FreeBSD$

PORTNAME=	emacs-wiki
PORTVERSION=	2.72
PORTREVISION=	15
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www.mwolson.org/static/dist/emacs-wiki/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create and use hyperlinks and simple formatting in plain text files

RUN_DEPENDS=	xml-parse.el${EMACS_PKGNAMESUFFIX}>0:textproc/xml-parse.el@${EMACS_FLAVOR} \
		htmlize.el${EMACS_PKGNAMESUFFIX}>0:textproc/htmlize.el@${EMACS_FLAVOR}

USES=		emacs makeinfo

OPTIONS_DEFINE=	CONTRIB
CONTRIB_DESC=	Install extra packages. This can shadow versions already there.
OPTIONS_SUB=	yes

INFO=		emacs-wiki
LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

do-build:
	(cd ${WRKSRC}; makeinfo --no-split emacs-wiki.texi)

do-install:
	${MKDIR} ${STAGEDIR}${LISPDIR}
.for i in *.el
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/emacs-wiki.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-CONTRIB-on:
	${MKDIR} ${STAGEDIR}${LISPDIR}/contrib
.for i in *.el
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${STAGEDIR}${LISPDIR}/contrib
.endfor

.include <bsd.port.mk>
