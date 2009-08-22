# ex:ts=8
# Ports collection Makefile for:	gdis
# Date created:			Mar 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gdis
PORTVERSION=	0.89
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	-source.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display and manipulation of isolated molecules and periodic systems

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

USE_GL=		yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

CFLAGS+=	-DINSTALL=\"\\\"${DATADIR}\\\"\"

PORTDOCS=	CHANGELOG README TODO
PLIST_FILES=	bin/gdis %%DATADIR%%/gdis.elements %%DATADIR%%/gdis.library \
		%%DATADIR%%/gdis.manual
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdis ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
.for file in gdis.elements gdis.library gdis.manual
	${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGELOG README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
