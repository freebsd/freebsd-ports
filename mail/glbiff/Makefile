# New ports collection makefile for:	glbiff
# Date created:				18 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	glbiff
PORTVERSION=	0.3.5
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://www.dgp.utoronto.ca/~mac/code/projects/ \
		http://freebsd.unixfreunde.de/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xbiff-like program for X Window System with nice 3D output

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GL=		glut
GNU_CONFIGURE=	yes

CFLAGS+=	${PTHREAD_CFLAGS} ${PTHREAD_LIBS:S/"//g}
CONFIGURE_ENV=	CFLAGS="${CFLAGS}"
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

MAN1=		glbiff.1
MAN5=		glbiffrc.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glbiff ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/glbiff.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/glbiffrc.5 ${PREFIX}/man/man5
	@${MKDIR} ${PREFIX}/share/examples/glbiff
	${INSTALL_DATA} ${WRKSRC}/glbiffrc.sample ${PREFIX}/share/examples/glbiff/dot.glbiffrc.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/glbiff
.for file in ChangeLog README README.last-minute TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/glbiff
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
