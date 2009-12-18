# ex:ts=8
# Ports collection makefile for:	nanoblogger-extra
# Date created:			Jun 19, 2009
# Whom:				Tobias Rehbein <tobias.rehbein@web.de>
#
# $FreeBSD$
#

PORTNAME=	nanoblogger-extra
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/nanoblogger/${PORTNAME}/Version%20${PORTVERSION}

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Extras for nanoblogger, a small weblog engine

RUN_DEPENDS=	nb:${PORTSDIR}/www/nanoblogger

DATADIR=	${PREFIX}/share/nanoblogger

NO_BUILD=	yes

do-install:
.for data in default lang plugins
	( cd ${WRKSRC}/${data} && ${CHMOD} 777 ${WRKSRC}/${data}/* && \
		${COPYTREE_SHARE} \* ${DATADIR}/${data} "! -empty" )
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in COPYING README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}/html
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/examples/nanoblogger.bash_completion ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
