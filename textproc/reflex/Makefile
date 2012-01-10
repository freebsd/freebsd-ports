# New ports collection makefile for:    reflex
# Date created:         10 January 2012
# Whom:                 bf@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	reflex
PORTVERSION=	20100906
CATEGORIES=	textproc
MASTER_SITES=	http://invisible-island.net/datafiles/release/ LOCAL/bf
DISTNAME=	reflex

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Relocalizable fast lexical scanner

LICENSE=	BSD

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	YACC="${YACC}"
MAN1=	reflex.1
PLIST_FILES=	bin/reflex bin/reflex++ include/reFlexLexer.h lib/librefl.a
WRKSRC =	${WRKDIR}/reflex-${PORTVERSION}

regression-test test: check

.for t in check bigcheck
${t}: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} ${t};

.endfor

.include <bsd.port.mk>
