# New ports collection makefile for:    scsh
# Date created:         Jul, 15, 1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#

PORTNAME=	scsh
PORTVERSION=	0.5.1
CATEGORIES=	shells lang
MASTER_SITES=	ftp://ftp-swiss.ai.mit.edu/pub/su/scsh/ \
		http://www2.cons.org:8000/freebsd-distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cracauer

MAINTAINER=	alex@FreeBSD.org

CONFIGURE_ENV+=	LDFLAGS="-Wl,-E"

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
BROKEN=		bus errors on unaligned accesses in scshvm
.endif

GNU_CONFIGURE=	yes

ALL_TARGET=	enough
MAN1=		scsh.1
STRIP=

post-install:
	@strip ${PREFIX}/bin/scsh
	(cd ${WRKSRC} ; \
	 ${INSTALL_DATA} README RELEASE NEWS COPYING ${PREFIX}/lib/scsh/doc)
	${RM} -f ${PREFIX}/share/doc/scsh
	${LN} -fs ${PREFIX}/lib/scsh/doc ${PREFIX}/share/doc/scsh

.include <bsd.port.post.mk>
