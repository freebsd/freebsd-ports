# New ports collection makefile for:	pine-pgp-filters
# Date created:				22 January 2003
# Whom:					dougb
#
# $FreeBSD$
#

PORTNAME=	pine-pgp-filters
PORTVERSION=	1.0
CATEGORIES=	mail
MASTER_SITES=	http://dougbarton.net/FreeBSD/Downloads/ \
		${MASTER_SITE_LOCAL}/dougb

MAINTAINER=	DougB@FreeBSD.org

do-build:
	cd ${WRKSRC} && ./configure --prefix=${PREFIX}

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} ${DOCSDIR}
.for file in INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
