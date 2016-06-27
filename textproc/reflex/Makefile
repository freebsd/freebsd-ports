# Created by: bf@FreeBSD.org
# $FreeBSD$

PORTNAME=	reflex
PORTVERSION=	20131209
CATEGORIES=	textproc
MASTER_SITES=	ftp://invisible-island.net/reflex/ LOCAL/bf
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Relocalizable fast lexical scanner

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	YACC="${YACC}"
PLIST_FILES=	bin/reflex bin/reflex++ include/reFlexLexer.h \
		lib/librefl.a man/man1/reflex.1.gz
WRKSRC=		${WRKDIR}/reflex-${PORTVERSION}

regression-test test: check

.for t in check bigcheck
${t}: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
	${MAKE_ARGS} ${t};)

.endfor

.include <bsd.port.mk>
