# New ports collection makefile for:	xlHtml
# Date created:				27 March 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xlhtml
PORTVERSION=	0.2.8
CATEGORIES=	textproc
MASTER_SITES=	http://www.xlhtml.org/
DISTNAME=	xlHtml-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	cole.2:${PORTSDIR}/textproc/cole

USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/cole"

MAN1=		pptHtml.1 xlHtml.1

pre-build:
	@${RM} -f ${WRKSRC}/cole.h
	@find ${WRKSRC} -type f | xargs ${GREP} -l '\.\./cole\.h' | \
		xargs ${PERL} -pi -e 's|\.\./cole\.h|cole/cole.h|g'

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
