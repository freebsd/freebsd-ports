# New ports collection makefile for:	mod_gzip Apache module
# Date created:		Dec 18 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_layout
PORTVERSION=	3.2
CATEGORIES=	www
MASTER_SITES=	http://software.tangent.org/download/

MAINTAINER=	sheepkiller@cultdeadsheep.org

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's!apxs!${LOCALBASE}/sbin/apxs!g' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/directives
	${INSTALL_DATA} ${WRKSRC}/faq.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/directives/* ${DOCSDIR}/directives
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
