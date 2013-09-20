# Created by: Matthew X. Economou <xenophon+fbsdports@irtnog.org>
# $FreeBSD$

PORTNAME=	django-openid-auth
PORTVERSION=	0.4
CATEGORIES=	www security python
MASTER_SITES=	http://launchpadlibrarian.net/80020365/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	OpenID integration for django.contrib.auth

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.3.1:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}openid>=2.2.5:${PORTSDIR}/security/py-openid

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

NO_WRKSUBDIR=	yes

PORTDOCS=	*.txt *.html
PORTEXAMPLES=	example_consumer

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt	${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/TODO.txt	${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/openid.html	${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/openid.txt	${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/example_consumer
	${INSTALL_MAN} ${WRKSRC}/example_consumer/* ${EXAMPLESDIR}/example_consumer
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
