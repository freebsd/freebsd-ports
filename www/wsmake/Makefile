# New ports collection makefile for: wsmake
# Date created:        31 May, 2002
# Whom:                Joseph Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	wsmake
PORTVERSION=	0.6.4
CATEGORIES=	www
MASTER_SITES=	${WSMAKE_MASTER_SITE}/dwnlds/stable/ \
		${WSMAKE_MASTER_SITE}/docs/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} examples.tar.gz
.ifndef NOPORTDOCS
DISTFILES+=	user-manual-html.tar.gz
.endif
DIST_SUBDIR=	wsmake
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	jkoshy@freebsd.org

USE_BZIP2=	YES
GNU_CONFIGURE=	YES

WSMAKE_MASTER_SITE=	http://www.wsmake.org
WSMAKE_DOCDIR=	${PREFIX}/share/doc/wsmake
WSMAKE_EXDIR=	${PREFIX}/share/examples/wsmake

# Install examples and optional documentation.
post-install:
	${MKDIR} ${WSMAKE_EXDIR}
	cd ${WSMAKE_EXDIR} && \
		 ${TAR} -xzf ${_DISTDIR}/examples.tar.gz --exclude '*/CVS/*'
.for ex in 1 2 3 4 5 6 7 8 9 10 11 12 13
	${MV} ${WSMAKE_EXDIR}/examples/ex${ex} ${WSMAKE_EXDIR}
.endfor
	${RM} -rf ${WSMAKE_EXDIR}/examples
.ifndef NOPORTDOCS
	${MKDIR} ${WSMAKE_DOCDIR}
	cd ${WSMAKE_DOCDIR} && \
		${TAR} -xzf ${_DISTDIR}/user-manual-html.tar.gz
	${LN} ${WSMAKE_DOCDIR}/user-manual/book1.html ${WSMAKE_DOCDIR}/user-manual/index.html
.endif

.include <bsd.port.mk>
