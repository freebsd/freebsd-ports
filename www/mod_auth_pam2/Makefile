# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	mod_auth_pam
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://pam.sourceforge.net/mod_auth_pam/dist/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2
DISTNAME=	${PORTNAME}-2.0-${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to use PAM modules for user authentication

USES=		apache:2.2+
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*.html
PORTEXAMPLES=	pam-httpd.sample

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

AP_EXTRAS+=	-lpam

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/httpd ${STAGEDIR}${EXAMPLESDIR}/pam-httpd.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
