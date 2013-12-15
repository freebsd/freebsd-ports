# Created by: Dominic Marks <dom@goodforbusiness.co.uk>
# $FreeBSD$

PORTNAME=	mod_line_edit
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/mod_line_edit/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.c
EXTRACT_SUFX=

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for simple text rewriting

LICENSE=	GPLv2

USE_APACHE=	22+

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

pre-extract:
	@${MKDIR} ${WRKSRC}

do-extract:
	@${CP} ${DISTDIR}/${PORTNAME}.c ${WRKSRC}

.include <bsd.port.mk>
