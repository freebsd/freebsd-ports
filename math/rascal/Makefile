# ex:ts=8
# New ports collection makefile for:	rascal
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rascal
PORTVERSION=	0.3.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_BISON=	yes
#USE_GNOME=	yes
WRKSRC=		${WRKDIR}/Rascal-${PORTVERSION}
USE_GMAKE=	yes
#ALL_TARGET=	rascal grascal

MAN1=	rascal.1

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g ; \
		s,g\+\+,${CXX},g ; \
		s,doc/,share/doc/,g ; \
		s,gnome-config,${GNOME_CONFIG},g ; \
		s,CC,CXX,g" ${WRKSRC}/Makefile
.for file in hoc.y rascal.1
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rascal ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/rascal.rc ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/rascal.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
.for file in rascal.ps rascal.pdf CHANGES TEST TOOLBOXTEST
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/rascal_html/* ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
