# Created by: ijliao
# $FreeBSD$

PORTNAME=	mftrace
PORTVERSION=	1.2.18
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://lilypond.org/download/sources/mftrace/ \
		LOCAL/nivit/${PORTNAME}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Scalable PostScript (Type1) Fonts for MetaFont

RUN_DEPENDS=	t1asm:${PORTSDIR}/print/t1utils \
		fontforge:${PORTSDIR}/print/fontforge

.if defined(WITH_AUTOTRACE)
BUILD_DEPENDS+=	autotrace:${PORTSDIR}/graphics/autotrace
RUN_DEPENDS+=	autotrace:${PORTSDIR}/graphics/autotrace
.else
BUILD_DEPENDS+=	potrace:${PORTSDIR}/graphics/potrace
RUN_DEPENDS+=	potrace:${PORTSDIR}/graphics/potrace
.endif

# Python3 ready
USE_TEX=	base texmf
GNU_CONFIGURE=	yes
USES=		gmake python
MAKEFILE=	GNUmakefile


PLIST_FILES=	\
		bin/gf2pbm \
		bin/mftrace \
		%%PYTHON_SITELIBDIR%%/afm.py \
		%%PYTHON_SITELIBDIR%%/tfm.py \
		man/man1/mftrace.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gf2pbm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mftrace ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mftrace.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tfm.py ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/afm.py ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
