# ex:ts=8
# Ports collection makefile for:  sniffit
# Date created:			  28 Mar 1998
# Whom:				  bsdx
#
# $FreeBSD$
#

PORTNAME=	sniffit
PORTVERSION=	0.3.7b
CATEGORIES=	net security
MASTER_SITES=	http://reptile.rug.ac.be/~coder/sniffit/files/  \
		ftp://ftp.freebsd.org/pub/FreeBSD/local-distfiles/obrien/
DISTNAME=	sniffit.0.3.7.beta

MAINTAINER=	obrien@FreeBSD.org

GNU_CONFIGURE=	yes
ALL_TARGET=
MAN5=		sniffit.5
MAN8=		sniffit.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sniffit ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/sniffit.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/sniffit.8 ${PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sniffit
	${INSTALL_MAN} ${WRKSRC}/README.FIRST ${PREFIX}/share/doc/sniffit
.endif

.include <bsd.port.mk>
