# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cjc
PORTVERSION=	1.2.1
CATEGORIES=	net-im python
MASTER_SITES=	http://cloud.github.com/downloads/Jajcus/cjc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Console Jabber Client

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyxmpp>=1.1.0:${PORTSDIR}/net-im/py-pyxmpp

USE_PYTHON=	2

NO_STAGE=	yes
post-patch:
	@${GREP} -lR "/usr/bin/python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s|/usr/bin/python|${PYTHON_CMD}|"
	@${REINPLACE_CMD} -e \
		"s|prefix=.*|prefix=${PREFIX}| ; \
		 /pkg_docdir/s|^|#|g ; \
		 s|INSTALL=.*|INSTALL=${INSTALL}| ; \
		 s|INSTALL_DATA=.*|INSTALL_DATA=${INSTALL_DATA}| ; \
		 s|INSTALL_DIR=.*|INSTALL_DIR=${MKDIR}|g ; \
		 s|python |${PYTHON_CMD} |g" ${WRKSRC}/Makefile

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
.endif

.include <bsd.port.mk>
