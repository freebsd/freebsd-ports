# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jailkit
PORTVERSION=	2.19
CATEGORIES=	shells
MASTER_SITES=	http://olivier.sessink.nl/jailkit/ \
		http://www.sfr-fresh.com/unix/privat/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Utilities to limit user accounts to specific files and/or commands

LICENSE=	BSD3CLAUSE

USES=		python:2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHONINTERPRETER=${PYTHON_CMD}

PORTDOCS=	COPYRIGHT README.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jk_uchroot \
		${STAGEDIR}${PREFIX}/sbin/jk_socketd \
		${STAGEDIR}${PREFIX}/sbin/jk_chrootlaunch \
		${STAGEDIR}${PREFIX}/sbin/jk_chrootsh \
		${STAGEDIR}${PREFIX}/sbin/jk_lsh

.include <bsd.port.mk>
