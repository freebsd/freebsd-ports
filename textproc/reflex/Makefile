# Created by: bf@FreeBSD.org
# $FreeBSD$

PORTNAME=	reflex
PORTVERSION=	20100906
CATEGORIES=	textproc
MASTER_SITES=	ftp://invisible-island.net/reflex/ LOCAL/bf
EXTRACT_SUFX=	.tgz

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

NO_STAGE=	yes
.include <bsd.port.mk>
