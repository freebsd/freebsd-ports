# New ports collection makefile for:	lshell
# Date created:		2009-08-01
# Whom:			Sylvio Cesar <scjamorim@bsd.com.br>
#
# $FreeBSD$
#

PORTNAME=	lshell
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Shell environment to limited sets of commands to user's

RUN_DEPENDS=	python:${PORTSDIR}/lang/python
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_PYDISTUTILS=	yes
USE_PYTHON=	yes

SHELLS=		/etc/shells

MAN1=	lshell.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}/
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
