# New ports collection makefile for:	libxpg4-ns
# Date created:		27 February 1999
# Whom:			sada
#
# $FreeBSD$
#

PORTNAME=	libxpg4-ns
PORTVERSION= 	3.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PORTS_JP} \
		http://people.FreeBSD.org/~sada/distfiles/
DISTNAME=	libxpg4-3.3

MAINTAINER=	sada@FreeBSD.ORG

INSTALLS_SHLIBS=	yes

MAKE_ENV+=	OBJFORMAT=aout SHLIB_MAJOR=2 SHLIB_MINOR=0
PORTOBJFORMAT=	aout

LIBDIR=		${PREFIX}/lib/aout
SRCDIR=		/usr/src

pre-build:
.if !exists(/usr/lib/aout/c++rt0.o)
	@${CAT} ${FILESDIR}/message.nolib
	@${FALSE}
.endif

pre-install:
	${MKDIR} ${LIBDIR}

extract-from-freebsd: # only for port maintainer.
.if exists(/usr/src/lib)
	@${RM} -rf ${WRKSRC}
	@${MKDIR} ${WRKSRC}
	@tar cfC - ${SRCDIR}/lib/libc locale | tar xfC - ${WRKSRC}
	@${CP} ${SRCDIR}/lib/libxpg4/Makefile ${WRKSRC}/
.else
	@${ECHO} You should INSTALL \"src/lib\" distribution"
.endif

private-distribution: # only for port maintainer.
	@(cd ${WRKDIR}; find ${DISTNAME} -type f | ${GREP} -v 'CVS' | ${SED} -e 's;^./;;' | tar czfCT ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} . -)

.include <bsd.port.mk>
