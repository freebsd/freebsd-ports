# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	ssh-multiadd
PORTVERSION=	1.3.2
CATEGORIES=	security
MASTER_SITES=	SUNSITE/system/network/telnet

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to add multiple ssh keys to the authentication agent

USES=		python:run
NO_BUILD=	yes

PLIST_FILES=	bin/ssh-multiadd man/man1/ssh-multiadd.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin/python2|${PYTHON_CMD}| ; \
		s|#break|break|' ${WRKSRC}/ssh-multiadd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ssh-multiadd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ssh-multiadd.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
