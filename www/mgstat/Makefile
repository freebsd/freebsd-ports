# New ports collection makefile for:	mgstat
# Date created:		11 May 2001
# Whom:			jeh@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mgstat
PORTVERSION=	0.4.1
CATEGORIES=	www
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/

MAINTAINER=	jeh@FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX}

MGDOCDIR=	${PREFIX}/share/doc/mgstat

post-install:
.if !defined(NOPORTDOCS)
	@if ! [ -d ${MGDOCDIR} ]; then ${MKDIR} ${MGDOCDIR}; fi
	${INSTALL_DATA} ${WRKSRC}/Copyright ${MGDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${MGDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/USAGE ${MGDOCDIR}
.endif

.include <bsd.port.mk>
