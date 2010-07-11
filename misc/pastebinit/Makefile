# New ports collection makefile for:   pastebinit
# Date created:        Thu Feb 21 00:21:23 EST 2008
# Whom:                comperr <comperr.extra@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pastebinit
PORTVERSION=	0.11
CATEGORIES=	misc python
MASTER_SITES=	http://www.stgraber.org/download/projects/pastebin/

MAINTAINER=	ports@eitanadler.com
COMMENT=	A command line utility for pastebing

USE_PYTHON=	yes

NO_BUILD=	yes

PLIST_FILES=	bin/pastebinit

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/bin/python#${PYTHON_CMD}#' \
	${WRKSRC}/${PORTNAME}

do-install:
	 ${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
