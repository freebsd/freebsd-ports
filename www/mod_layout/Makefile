# New ports collection makefile for:	mod_gzip Apache module
# Date created:		Dec 18 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_layout
PORTVERSION=	3.0.3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.tangent.org/pub/apache/ \
		http://software.tangent.org/download/

MAINTAINER=	petef@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

MAKE_ENV=	APXS=${LOCALBASE}/sbin/apxs

post-patch:
	@${PERL} -pi -e 's!APXS=apxs!APXS?=apxs!' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/directives
	${INSTALL_DATA} ${WRKSRC}/faq.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/directives/* ${DOCSDIR}/directives
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
