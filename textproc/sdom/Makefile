# ex:ts=8
# Ports collection makefile for:	SDOM
# Date created:			Mar 22, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdom
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	textproc scheme
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of the W3C DOM recommendation in Scheme

RUN_DEPENDS=	${LOCALBASE}/share/guile/site/config/load.scm:${PORTSDIR}/devel/guile-lib

ALL_TARGET=	guile

FILES=	core.scm events.scm ls.scm
PLIST_FILES=	share/guile/sdom/core.scm \
		share/guile/sdom/events.scm \
		share/guile/sdom/ls.scm
PLIST_DIRS=	share/guile/sdom

INFO=	sdom

do-install:
	@${MKDIR} ${PREFIX}/share/guile/sdom
.for f in ${FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/guile/sdom
.endfor
	@${INSTALL_DATA} ${WRKSRC}/sdom.info ${PREFIX}/info

.include <bsd.port.mk>
