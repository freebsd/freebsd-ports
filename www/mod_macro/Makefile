# ex:ts=8
# Ports collection makefile for:	mod_macro
# Date created:			Nov 20, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mod_macro
PORTVERSION=	1.1.2
CATEGORIES=	www
MASTER_SITES=	http://www.cri.ensmp.fr/~coelho/mod_macro/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache module for use macros in config files

USE_APACHE=	yes

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME} ${WRKSRC}/${PORTNAME}.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
