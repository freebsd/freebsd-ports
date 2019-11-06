# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_cvs
PORTVERSION=	0.5.91
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://resare.com/noa/mod_cvs/dist/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Module that makes Apache 2 CVS aware

BROKEN=		unfetchable

LICENSE=	AFL12
LICENSE_NAME=	Academic Free License 1.2
LICENSE_FILE=	${WRKSRC}/LICENSE.AFL
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		apache:2.2+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PORTDOCS=	reference.html guide.html README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS:NREADME}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
