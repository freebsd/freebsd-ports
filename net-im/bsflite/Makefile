# New ports collection makefile for:	bsflite
# Date created:				3 June 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	bsflite
DISTVERSION=	0.80
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=bsflite

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A lightweight command line AIM client

USE_REINPLACE=	yes

OSCAR_PORT?=	5190

.include <bsd.port.pre.mk>

.if ${OSCAR_PORT} == "5190"
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Note:"
	@${ECHO_MSG} "If you're behind a firewall you might want to set OSCAR_PORT"
	@${ECHO_MSG} "a port other than ${OSCAR_PORT}."
	@${ECHO_MSG} ""
.endif

.if ${OSCAR_PORT} != 5190
post-patch:
	@${REINPLACE_CMD} -e 's|^\(#define OSCAR_PORT\) 5190|\1 ${OSCAR_PORT}|' \
		${WRKSRC}/imcomm/imcomm.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsflite ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config-example ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in COPYING ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
