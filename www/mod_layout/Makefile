# New ports collection makefile for:	mod_gzip Apache module
# Date created:		Dec 18 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_layout
PORTVERSION=	3.2.1
CATEGORIES=	www
MASTER_SITES=	http://software.tangent.org/download/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module to wrap served pages with a header and/or footer

USE_APACHE=	yes
USE_REINPLACE=	yes

CONFLICTS=	mod_layout-4.* apache-contrib-1.*

CFLAGS+=	-fPIC

post-patch:
	@${REINPLACE_CMD} -e 's!apxs!${LOCALBASE}/sbin/apxs!g; \
		s!-DDEBUG!$$(CFLAGS)!g' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/directives
	${INSTALL_DATA} ${WRKSRC}/faq.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/directives/* ${DOCSDIR}/directives
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
