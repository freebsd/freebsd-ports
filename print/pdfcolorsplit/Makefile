# New ports collection makefile for:	pdfcolorsplit
# Date created:				2011-08-26
# Whom:					Aldis Berjoza <aldis@bsdroot.lv>
#
# $FreeBSD$
#

PORTNAME=	pdfcolorsplit
PORTVERSION=	2011.08.26
CATEGORIES=	print python
MASTER_SITES=	http://files.bsdroot.lv/my/FreeBSD/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Split your pdf into 2 pdf, color and bw, for printing

LICENSE=	GPLv2

RUN_DEPENDS=	pdftk:${PORTSDIR}/print/pdftk \
		pdftoppm:${PORTSDIR}/graphics/xpdf

USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_XZ=		yes

PLIST_FILES=	bin/${PORTNAME}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
