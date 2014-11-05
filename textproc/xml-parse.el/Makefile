# Created by: Dryice Liu <dryice@liu.com.cn>
# $FreeBSD$

PORTNAME=	xml-parse.el
PORTVERSION=	1.5
PORTREVISION=	5
CATEGORIES=	textproc elisp
MASTER_SITES=	http://dryice.name/computer/FreeBSD/distfiles/ \
		http://sacha.free.net.ph/notebook/emacs/ \
		http://ports.toco-domains.de/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@toco-domains.de
COMMENT=	Code to efficiently read/write XML data with Elisp

USE_EMACS=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
