# New ports collection makefile for:	tcmplex-panteltje
# Date created:		2004-10-21
# Whom:			Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcmplex-panteltje
PORTVERSION=	0.4.7
CATEGORIES=	multimedia
MASTER_SITES=	http://ip51cf87c4.direct-adsl.nl/panteltje/dvd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Re-write of the A/V multiplexer from the transcode distribution

DEPRECATED=     Upstream has disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

ALL_TARGET=	a.out

PLIST_FILES=	bin/tcmplex-panteltje

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES COPYRIGHT LICENSE README
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
