# New ports collection makefile for:	libxpg4-ns
# Version required:	3.1-R
# Date created:		27 February 1999
# Whom:			sada
#
# $FreeBSD$
#

DISTNAME=	libxpg4-3.1r
PKGNAME=	libxpg4-ns-3.1r
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_PORTS_JP} \
		http://WWW.FreeBSD.ORG/~sada/distfiles/

MAINTAINER=	sada@FreeBSD.ORG

MAKE_ENV+=	OBJFORMAT=aout SHLIB_MAJOR=2 SHLIB_MINOR=0 \
		LDDESTDIRENV=LIBRARY_PATH=${PREFIX}/lib/aout
PORTOBJFORMAT=	aout

LIBDIR=		${PREFIX}/lib/aout
SRCDIR=		/usr/src

pre-install:
	${MKDIR} ${LIBDIR}

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${LIBDIR}

extract-from-freebsd: # only for port maintainer.
.if exists(/usr/src/lib)
	${RM} -rf ${WRKSRC}
	${MKDIR} ${WRKSRC}
	tar cfC - ${SRCDIR}/lib/libc locale | tar xfC - ${WRKSRC}
	${CP} ${SRCDIR}/lib/libxpg4/Makefile ${WRKSRC}/
.else
	${ECHO} You should INSTALL \"src/lib\" distribution"
.endif

private-distribution: # only for port maintainer.
	tar czfC ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKDIR} ${DISTNAME}

.include <bsd.port.mk>
