# ex:ts=8
# Ports collection makefile for:	mftrace (formerly pktrace)
# Date created:			Jun w, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

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
USE_PYTHON=	yes
USE_TEX=	base texmf
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	mftrace.1
.endif

PLIST_FILES=	\
		bin/gf2pbm \
		bin/mftrace \
		%%PYTHON_SITELIBDIR%%/afm.py \
		%%PYTHON_SITELIBDIR%%/tfm.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gf2pbm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mftrace ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/mftrace.1 ${MANPREFIX}/man/man1
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/tfm.py ${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/afm.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
