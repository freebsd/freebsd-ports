# New ports collection makefile for:	hagelslag
# Date created:		14 February 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	hagelslag
PORTVERSION=	0.12.1
CATEGORIES=	net
MASTER_SITES=	http://tiefighter.et.tudelft.nl/hagelslag/ \
		ftp://tiefighter.et.tudelft.nl/pub/hagelslag/v${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	johann@egenetics.com

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

USE_GMAKE=	yes
MAKEFILES=	Makefile gui/Makefile gui-api/Makefile
HS_DOCDIR=	${PREFIX}/share/doc/${PORTNAME}

post-patch:
.for mfile in ${MAKEFILES}
	@ ${PERL} -pi -e 's#make -C#\$${MAKE} -C#' ${WRKSRC}/${mfile}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${HS_DOCDIR}
	@ ${INSTALL_MAN} ${WRKSRC}/doc/* ${HS_DOCDIR}
.endif

.include <bsd.port.mk>
