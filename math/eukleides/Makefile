# ex:ts=8
# Ports collection makefile for:	eukleides
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	eukleides
PORTVERSION=	0.9.2.2
CATEGORIES=	math
MASTER_SITES=	http://perso.wanadoo.fr/obrecht/download/
DISTNAME=	${PORTNAME}.${PORTVERSION:R}rev${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Euclidean geometry drawing language

RUN_DEPENDS=	pstoedit:${PORTSDIR}/graphics/pstoedit \
		epstopdf:${PORTSDIR}/print/teTeX

USE_BISON=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -c"
ALL_TARGET=	eukleides info

MAN1=		eukleides.1
MLINKS=		eukleides.1 euk2eps.1 \
		eukleides.1 euk2edit.1
INFO=		eukleides
PLIST_FILES=	bin/euk2edit bin/euk2eps bin/eukleides

post-patch:
	${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|#!/bin/bash|#!/bin/sh|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eukleides ${PREFIX}/bin/eukleides
	${INSTALL_SCRIPT} ${WRKSRC}/euk2edit ${PREFIX}/bin/euk2edit
	${INSTALL_SCRIPT} ${WRKSRC}/euk2eps ${PREFIX}/bin/euk2eps
	${INSTALL_MAN} ${WRKSRC}/eukleides.man ${MANPREFIX}/man/man1/eukleides.1
	${INSTALL_DATA} ${WRKSRC}/eukleides.info ${PREFIX}/info/eukleides.info
	@install-info ${PREFIX}/info/eukleides.info ${PREFIX}/info/dir

.include <bsd.port.mk>
