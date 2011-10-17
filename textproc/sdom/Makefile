# ex:ts=8
# Ports collection makefile for:	SDOM
# Date created:			Mar 22, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdom
PORTVERSION=	0.5.1
CATEGORIES=	textproc scheme
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of the W3C DOM recommendation in Scheme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	guile>=0:${PORTSDIR}/devel/guile-lib

NO_BUILD=	yes

INFO=		sdom
PLIST_FILES=	share/guile/sdom/common.scm \
		share/guile/sdom/core.scm \
		share/guile/sdom/events.scm \
		share/guile/sdom/ls.scm \
		share/guile/sdom/parser.scm
PLIST_DIRS=	share/guile/sdom

do-install:
	@${MKDIR} ${PREFIX}/share/guile/sdom
.for f in common.scm core.scm events.scm ls.scm parser.scm
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/guile/sdom
.endfor
	${INSTALL_DATA} ${WRKSRC}/sdom.info ${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
