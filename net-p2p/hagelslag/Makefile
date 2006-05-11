# New ports collection makefile for:	hagelslag
# Date created:		14 February 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	hagelslag
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://tiefighter.et.tudelft.nl/hagelslag/ \
		ftp://tiefighter.et.tudelft.nl/pub/hagelslag/v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flexible command-line Gnutella implementation with advanced features

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

USE_GMAKE=	yes
MAKEFILES=	Makefile gui/Makefile src/Makefile
HS_DOCDIR=	${PREFIX}/share/doc/${PORTNAME}

post-patch:
.for mfile in ${MAKEFILES}
	@ ${REINPLACE_CMD} -e 's#make -C#\$${MAKE} -C#' ${WRKSRC}/${mfile}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${HS_DOCDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/* ${HS_DOCDIR}
.endif

.include <bsd.port.mk>
