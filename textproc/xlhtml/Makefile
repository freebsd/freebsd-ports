# New ports collection makefile for:	xlhtml
# Date created:				27 March 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xlhtml
PORTVERSION=	0.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.xlhtml.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax
DISTNAME=	xlHtml-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	cole.2:${PORTSDIR}/textproc/cole

USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/cole"

MAN1=		ppthtml.1 xlhtml.1

do-install:
	(cd ${WRKSRC}/xlhtml && ${MAKE} ${INSTALL_TARGET})
	(cd ${WRKSRC}/ppthtml && ${MAKE} ${INSTALL_TARGET})
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xlhtml
	${INSTALL_MAN} ${WRKSRC}/xlhtml/README \
		${PREFIX}/share/doc/xlhtml/README.xlhtml
	${INSTALL_MAN} ${WRKSRC}/ppthtml/README \
		${PREFIX}/share/doc/xlhtml/README.ppthtml
.endif

.include <bsd.port.mk>
