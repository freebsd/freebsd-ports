# ex:ts=8
# Ports collection makefile for:  vntex
# Date created:			  Tue Feb 06, 2001
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	vntex
PORTVERSION=	1.0
CATEGORIES=	vietnamese print
MASTER_SITES=	http://www.fi.muni.cz/~thanh/download/
DISTNAME=	vntex

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	teTeX Vietnamese language + font support

#	actually just need to make sure ${PREFIX}/share/texmf/tex/ exists
RUN_DEPENDS=	virtex:${PORTSDIR}/print/teTeX

BROKEN=		Broken dependency
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_ZIP=	yes
NO_BUILD=	yes

do-install:
	@cd ${WRKDIR}/tex ; tar cf - . \
		| (cd ${PREFIX}/share/texmf/tex ; tar --unlink -xpBf -)
	@cd ${WRKDIR}/fonts ; tar cf - . \
		| (cd ${PREFIX}/share/texmf/fonts ; tar --unlink -xpBf -)
	@${PREFIX}/bin/texconfig rehash
.if !defined(NOPORTDOCS)
	@#	${MKDIR} ${PREFIX}/share/doc/vntex
	@#	${INSTALL_MAN} ${WRKSRC}/foo.ps ${PREFIX}/share/doc/vntex
.endif

.include <bsd.port.mk>
