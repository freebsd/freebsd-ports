# ex:ts=8
# Ports collection makefile for:	slurm
# Date created:			Tue Oct 30, 2002
# Whom:				Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	slurm
PORTVERSION=	0.0.6
CATEGORIES=	net
MASTER_SITES=	http://www.raisdorf.net/files/code/ \
		http://www.fachschaft.fh-kiel.de/~hscholz/slurm/ \
		http://www.toppoint.de/~hscholz/slurm/

MAINTAINER=	mich@freebsdcluster.org

LDFLAGS+=	-lncurses

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} slurm.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
