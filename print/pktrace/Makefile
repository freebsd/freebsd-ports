# ex:ts=8
# Ports collection makefile for:	pktrace
# Date created:			Jun w, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pktrace
PORTVERSION=	1.0.4
CATEGORIES=	print
MASTER_SITES=	http://www.cs.uu.nl/~hanwen/pktrace/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt
RUN_DEPENDS=	mktextfm:${PORTSDIR}/print/teTeX \
		autotrace:${PORTSDIR}/graphics/autotrace \
		t1asm:${PORTSDIR}/print/t1utils \
		pfaedit:${PORTSDIR}/print/pfaedit

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

MAN1=	pktrace.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gf2pbm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pktrace ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pktrace.1 ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/tfm.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
