# New ports collection makefile for:	mod_gzip Apache module
# Date created:		Dec 18 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_layout
PORTVERSION=	2.8.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.tangent.org/pub/apache/ \
		http://www.tangent.org/mod_layout/

MAINTAINER=	mi@aldan.algebra.com

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/sbin/apxs -c *.c

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/sbin/apxs -A -i ${PORTNAME}.so

.if !defined(NOPORTDOCS)
PLIST_SUB+=	DOC=''

post-install:
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.html \
		${PREFIX}/share/doc/${PORTNAME}

.else
PLIST_SUB+=	DOC='@comment '
.endif

.include <bsd.port.mk>
