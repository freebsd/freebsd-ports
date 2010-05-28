# New ports collection makefile for:	lshell
# Date created:		2009-08-01
# Whom:			Sylvio Cesar <scjamorim@bsd.com.br>
#
# $FreeBSD$
#

PORTNAME=	lshell
PORTVERSION=	0.9.12
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Shell environment to limited sets of commands to user's

USE_PYDISTUTILS=	yes
USE_PYTHON=	yes

SHELLS=		/etc/shells

MAN1=	lshell.1

PORTDOCS=	CHANGES COPYING README

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g; \
		s|share/man|${LOCALBASE}/man|g; 45d' ${WRKSRC}/setup.py
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
	${INSTALL_DATA} -p ${PREFIX}/etc/${PORTNAME}.conf.sample ${PREFIX}/etc/${PORTNAME}.conf ; \
	fi
	@${ECHO_MSG} "Updating ${SHELLS}"
	@${CP} ${SHELLS} ${SHELLS}.bak
	@(${GREP} -v ${PREFIX}/bin/${PORTNAME} ${SHELLS}.bak; \
	  ${ECHO_CMD} ${PREFIX}/bin/${PORTNAME}) > ${SHELLS}
	@${RM} ${SHELLS}.bak

.include <bsd.port.mk>
