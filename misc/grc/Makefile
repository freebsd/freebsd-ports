# ex:ts=8
# New ports collection makefile for:	grc
# Date created:			Mar 25, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grc
PORTVERSION=	1.3
CATEGORIES=	misc
MASTER_SITES=	http://kassiopeia.juls.savba.sk/~garabik/software/grc/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Colouriser

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

MAN1=	grc.1 grcat.1

post-patch:
.for file in grc grcat
	@${REINPLACE_CMD} -e "s|%%PYTHON_CMD%%|${PYTHON_CMD}|g ; \
		s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

do-install:
.for f in grc grcat
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${MAN1PREFIX}/man/man1
.endfor
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/conf.* ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/grc.conf ${PREFIX}/etc

.include <bsd.port.mk>
