# ex:ts=8
# Ports collection makefile for:	mftrace (formerly pktrace)
# Date created:			Jun w, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mftrace
PORTVERSION=	1.2.15
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	LOCAL/nivit/${PORTNAME}/ \
		http://lilypond.org/download/sources/mftrace/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Scalable PostScript (Type1) Fonts for MetaFont

RUN_DEPENDS=	mktextfm:${PORTSDIR}/print/teTeX \
		t1asm:${PORTSDIR}/print/t1utils \
		fontforge:${PORTSDIR}/print/fontforge

.if defined(WITH_POTRACE)
BUILD_DEPENDS+=	potrace:${PORTSDIR}/graphics/potrace
RUN_DEPENDS+=	potrace:${PORTSDIR}/graphics/potrace
.else
BUILD_DEPENDS+=	autotrace:${PORTSDIR}/graphics/autotrace
RUN_DEPENDS+=	autotrace:${PORTSDIR}/graphics/autotrace
.endif

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

MAN1=	mftrace.1

PLIST_FILES=	\
		bin/gf2pbm \
		bin/mftrace \
		lib/%%PYTHON_VERSION%%/site-packages/afm.py \
		lib/%%PYTHON_VERSION%%/site-packages/tfm.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gf2pbm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mftrace ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mftrace.1 ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/tfm.py ${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/afm.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
