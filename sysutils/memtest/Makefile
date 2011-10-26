# New ports collection makefile for:    memtest
# Date created:         18 Jun 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	memtest
PORTVERSION=	4.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://pyropus.ca/software/${PORTNAME}er/old-versions/
DISTNAME=	${PORTNAME}er-${PORTVERSION}

MAINTAINER=	question+fbsdports@closedsrc.org
COMMENT=	Utility to test for faulty memory subsystem

LICENSE=	GPLv2

MAN8=		${PORTNAME}.8
PLIST_FILES=	bin/memtest

post-patch:
	@${REINPLACE_CMD} -e 's|cc|${CC}|' \
		${WRKSRC}/conf-*
	@${MV} ${WRKSRC}/${PORTNAME}er.8 ${WRKSRC}/${MAN8}
	@${REINPLACE_CMD} -e 's|${PORTNAME}er |${PORTNAME} |g' \
			  -e 's| ${PORTNAME}er| ${PORTNAME}|' \
			  -e "s|${PORTNAME}er's|${PORTNAME}'s|" \
		${WRKSRC}/${MAN8}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}er ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${MAN8} ${PREFIX}/man/man8/${MAN8}

.include <bsd.port.mk>
