# ex:ts=8
# Ports collection makefile for:	slurm
# Date created:			Tue Oct 30, 2002
# Whom:				Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	slurm
PORTVERSION=	0.3.0
CATEGORIES=	net
MASTER_SITES=	http://www.raisdorf.net/files/code/ \
		http://www.fachschaft.fh-kiel.de/~hscholz/slurm/ \
		http://www.toppoint.de/~hscholz/slurm/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Slurm is a generic network load monitor

LDFLAGS+=	-lncurses

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

MAN1=	slurm.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/themes/* ${DATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/KEYS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
.endif

.include <bsd.port.mk>
