# New ports collection makefile for:	pine-pgp-filters
# Date created:				22 January 2003
# Whom:					dougb
#
# $FreeBSD$
#

PORTNAME=	pine-pgp-filters
PORTVERSION=	1.1
CATEGORIES=	mail
MASTER_SITES=	http://dougbarton.net/FreeBSD/Downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dougb

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	Simple, fast, sh-based filters to integrate Pine with gnupg, or pgp6

do-build:
	cd ${WRKSRC} && ./configure --prefix=${PREFIX}

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} ${DOCSDIR}
.for file in BUGS CHANGES INSTALL LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
