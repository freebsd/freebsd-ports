# ex:ts=8
# Ports collection makefile for:	eukleides
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	eukleides
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.eukleides.org/download/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Euclidean geometry drawing language

RUN_DEPENDS=	pstoedit:${PORTSDIR}/graphics/pstoedit \
		epstopdf:${PORTSDIR}/print/teTeX-base

USE_BISON=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -c"
ALL_TARGET=	eukleides info

MAN1=		eukleides.1
MLINKS=		eukleides.1 euk2eps.1 \
		eukleides.1 euk2edit.1
INFO=		eukleides

post-patch:
	${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|#!/bin/bash|#!/bin/sh|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eukleides ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/euk2edit ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/euk2eps ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/eukleides.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/eukleides.info ${PREFIX}/${INFO_PATH}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.euk ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
