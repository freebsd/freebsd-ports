# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	rawdog
PORTVERSION=	2.18
CATEGORIES=	news python
MASTER_SITES=	http://offog.org/files/ \
		ftp://ftp.i-scream.org/pub/offog.org/files/ \
		http://ftp.i-scream.org/pub/offog.org/files/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	A simple RSS aggregator

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
MAN1=		rawdog.1

PORTDOCS=	README

PKGMESSAGE=	${WRKDIR}/pkg-message

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/style.css ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.if !defined(NOPORTEXAMPLES) || !defined(NOPORTDOCS)
	@${ECHO_MSG} "    ---------------------------------------------" \
		>>${PKGMESSAGE}
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} "    Sample config and stylesheet installed in:" \
		>>${PKGMESSAGE}
	@${ECHO_MSG} "        ${EXAMPLESDIR}" >>${PKGMESSAGE}
.endif
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "    Please read the README:" >>${PKGMESSAGE}
	@${ECHO_MSG} "        ${DOCSDIR}/README" >>${PKGMESSAGE}
.endif
.if !defined(NOPORTEXAMPLES) || !defined(NOPORTDOCS)
	@${ECHO_MSG} "    ---------------------------------------------" \
		>>${PKGMESSAGE}
.endif

.include <bsd.port.mk>
