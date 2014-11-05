# Created by: KIMURA Yasuhiro <yasu@utahime.org>
# $FreeBSD$

PORTNAME=	c-sig
PORTVERSION=	3.8
PORTREVISION=	15
CATEGORIES=	mail elisp
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	tota/${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	yasu@utahime.org
COMMENT=	Signature insertion tool for Emacs

LICENSE=	GPLv2

USE_EMACS=	yes

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -q -f batch-byte-compile c-sig.el

do-install:
	@${MKDIR} ${STAGEDIR}${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/c-sig.el* ${STAGEDIR}${LISPDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in c-sig-eng.faq c-sig-eng.man c-sig-jp.faq c-sig-jp.man
	${INSTALL_MAN} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
