# New ports collection makefile for:   xml-lite.el
# Date created:                18 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	xml-lite.el
PORTVERSION=	1.1
PORTEPOCH=	1
CATEGORIES=	textproc elisp
MASTER_SITES=	http://dogbiscuit.org/mdub/software/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple XML-editing for GNU Emacs

EMACS_PORT_NAME?=	emacs21
EMACS_NO_BUILD_DEPENDS=	YES

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}
PLIST_FILES=	%%EMACS_VERSION_SITE_LISPDIR%%/xml-lite.el

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${PREFIX}/${LISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
