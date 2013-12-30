# Created by: Sylvio Cesar <scjamorim@bsd.com.br>
# $FreeBSD$

PORTNAME=	lshell
PORTVERSION=	0.9.15.1
CATEGORIES=	shells
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.9.15/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Shell environment to limited sets of commands to user's

USE_PYDISTUTILS=	yes
USE_PYTHON=	yes

PORTDOCS=	CHANGES COPYING README

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g; \
		s|share/man|${MANPREFIX}/man|g; 45d' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
