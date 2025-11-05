PORTNAME=	eval
PORTVERSION=	113
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://wuarchive.wustl.edu/pub/aminet/util/cli/ \
		http://www.netsw.org/math/calc/ \
		http://main.aminet.net/util/cli/
DISTNAME=	Eval${PORTVERSION}
EXTRACT_SUFX=	.lha

MAINTAINER=	slaven@rezic.de
COMMENT=	Full featured floating point expression evaluator

USES=		lha readline

CPPFLAGS+=	-DWANT_OBSOLETE_TYPEDEFS
WRKSRC=		${WRKDIR}/Eval/source

PLIST_FILES=	bin/Eval

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-extract:
	-${LN} -s Makefile.unx ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Eval ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
