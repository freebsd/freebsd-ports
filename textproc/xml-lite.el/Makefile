# New ports collection makefile for:   xml-lite.el
# Date created:                18 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	xml-lite.el
PORTVERSION=	1.29
CATEGORIES=	textproc elisp
MASTER_SITES=	http://members.ozemail.com.au/~mdub/software/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	fuyuki@mj.0038.net

EMACS_PORT_NAME?=	emacs21
EMACS_NO_BUILD_DEPENDS=	YES

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${PREFIX}/${LISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
