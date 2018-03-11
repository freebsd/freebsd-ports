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

USES=		apache:2.2+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${PORTNAME}.c ${WRKSRC}

.include <bsd.port.mk>
