# $FreeBSD$

PORTNAME=	automx
PORTVERSION=	0.9.2
CATEGORIES=	mail
MASTER_SITES=	http://www.automx.org/download/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Handles mail account profile requests from mail clients

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_wsgi.so:${PORTSDIR}/www/mod_wsgi2 \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml \
		wget:${PORTSDIR}/ftp/wget

USE_APACHE_RUN=	22+
USE_PYTHON=	yes
NO_BUILD=	yes
PORTDATA=	*
PORTDOCS=	*

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.options.mk>

post-patch:
# Generate pkg-message from INSTALL file; include lines from Section 5 onwards
	line=$$(${SED} -ne '/^Web Server/=' ${WRKSRC}/INSTALL) && \
		${SED} -ne "$$line,\$$p" ${WRKSRC}/INSTALL > ${PKGMESSAGE}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/src && \
	    ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR})
	${INSTALL_DATA} ${WRKSRC}/src/automx_wsgi.py ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/automx-test ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/conf/automx.conf \
		${STAGEDIR}${PREFIX}/etc/automx.conf.sample
.for s in 1 5
	${INSTALL_MAN} ${WRKSRC}/doc/man/man$s/* ${STAGEDIR}${PREFIX}/man/man$s/
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "[^m]*" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
