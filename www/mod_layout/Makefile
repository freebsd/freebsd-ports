# New ports collection makefile for:	mod_gzip Apache module
# Date created:		Dec 18 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_layout
PORTVERSION=	3.4
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module to wrap served pages with a header and/or footer

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13

CONFLICTS=	mod_layout-4.* mod_layout-5.* apache-contrib-1.*

PORTSCOUT=	limit:^3

CFLAGS+=	-fPIC

post-patch:
	@${REINPLACE_CMD} -e 's!apxs!${LOCALBASE}/sbin/apxs!g' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/directives
	${INSTALL_DATA} ${WRKSRC}/faq.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/directives/* ${DOCSDIR}/directives
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
