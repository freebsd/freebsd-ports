# ex:ts=8
# Ports collection makefile for:	font2svg
# Date created:			Jan 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	font2svg
PORTVERSION=	0.1.4
CATEGORIES=	print
MASTER_SITES=	http://www.gdv.uni-hannover.de/~peinecke/font2svg/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		gs:${PORTSDIR}/print/ghostscript-gnu

USE_REINPLACE=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|" \
		-e "s|/home/peinecke/cprog/font2svg|${DATADIR}|" \
		${WRKSRC}/font2svg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/font2svg ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/encodings ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/font2svg.ps ${DATADIR}

.include <bsd.port.mk>
