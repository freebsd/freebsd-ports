# ex:ts=8
# Ports collection makefile for:  lr
# Date created:                          Tue Jul 14, 2002
# Whom:                                  Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	lr
PORTVERSION=	1.6
CATEGORIES=	misc
MASTER_SITES=	http://www.seekrut.com/rk/

MAINTAINER=	mich@freebsdcluster.org

ALL_TARGET=	lr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
