# New ports collection makefile for:	xlHtml
# Version required:			0.2.6
# Date created:				27 March 2000
# Whom:					Maxim Sobolev <sobomax@altavista.net>
#
# $FreeBSD$
#

DISTNAME=	xlHtml-${VERSION}
PKGNAME=	xlhtml-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	http://www.gate.net/~ddata/xlHtml/

MAINTAINER=	sobomax@altavista.net

LIB_DEPENDS=	cole.2:${PORTSDIR}/textproc/cole

VERSION=	0.2.6
USE_LIBTOOL=	yes

do-install:
	(cd ${WRKSRC}/xlHtml && ${MAKE} ${INSTALL_TARGET})
	(cd ${WRKSRC}/pptHtml && ${MAKE} ${INSTALL_TARGET})
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xlHtml
	${INSTALL_MAN} ${WRKSRC}/xlHtml/README \
		${PREFIX}/share/doc/xlHtml/README.xlHtml
	${INSTALL_MAN} ${WRKSRC}/pptHtml/README \
		${PREFIX}/share/doc/xlHtml/README.pptHtml
.endif

.include <bsd.port.mk>
