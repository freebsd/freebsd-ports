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

WANT_APACHE=	13
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
PORTDOCS=	${PORTNAME}.html

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
