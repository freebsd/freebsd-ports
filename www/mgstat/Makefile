# New ports collection makefile for:	mgstat
# Date created:		11 May 2001
# Whom:			jeh@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mgstat
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produce graphs from mod_gzip log files

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

GNU_CONFIGURE=	yes

MGDOCDIR=	${PREFIX}/share/doc/mgstat

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@if ! [ -d ${MGDOCDIR} ]; then ${MKDIR} ${MGDOCDIR}; fi
	${INSTALL_DATA} ${WRKSRC}/Copyright ${MGDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${MGDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/USAGE ${MGDOCDIR}
.endif

.include <bsd.port.post.mk>
