# New ports collection makefile for:	mod_gzip Apache module
# Date created:		Dec 18 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_layout
PORTVERSION=	2.10.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.tangent.org/pub/apache/ \
		http://www.tangent.org/mod_layout/

MAINTAINER=	petef@databits.net

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

MAKE_ENV=	APXS=${LOCALBASE}/sbin/apxs

post-patch:
	@${PERL} -pi -e 's!-i -a -n!-i -A -n!; s!APXS=apxs!APXS?=apxs!' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/faq.html ${PREFIX}/share/doc/${PORTNAME}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
