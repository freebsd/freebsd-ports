# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	rawdog
PORTVERSION=	2.22
CATEGORIES=	news python
MASTER_SITES=	http://offog.org/files/ \
		http://ftp.i-scream.org/pub/offog.org/files/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Simple RSS aggregator

LICENSE=	GPLv2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/feedparser.py:textproc/py-feedparser@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils
NO_ARCH=	yes

PORTDOCS=	README

PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/style.css ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} "    ---------------------------------------------" \
		>>${PKGMESSAGE}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} "    Sample config and stylesheet installed in:" \
		>>${PKGMESSAGE}
	@${ECHO_MSG} "        ${EXAMPLESDIR}" >>${PKGMESSAGE}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "    Please read the README:" >>${PKGMESSAGE}
	@${ECHO_MSG} "        ${DOCSDIR}/README" >>${PKGMESSAGE}
.endif
.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} "    ---------------------------------------------" \
		>>${PKGMESSAGE}
.endif

.include <bsd.port.mk>
