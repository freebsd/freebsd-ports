# New ports collection makefile for:	xlHtml
# Date created:				27 March 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xlhtml
PORTVERSION=	0.2.7.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.xlhtml.org/
DISTNAME=	xlHtml-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	cole.2:${PORTSDIR}/textproc/cole

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
