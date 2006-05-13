# New ports collection makefile for:    memtest
# Date created:         18 Jun 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	memtest
PORTVERSION=	4.0.5
CATEGORIES=	sysutils
MASTER_SITES=	http://pyropus.ca/software/${PORTNAME}er/
DISTNAME=	${PORTNAME}er-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to test for faulty memory subsystem

MAN8=		${PORTNAME}.8
PLIST_FILES=	bin/memtest

post-patch:
	@${REINPLACE_CMD} -e 's|cc|${CC}|' \
		${WRKSRC}/conf-cc

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}er ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${MAN8:S/./er./g} ${PREFIX}/man/man8/${MAN8}

.include <bsd.port.mk>
