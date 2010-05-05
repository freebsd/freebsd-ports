# New ports collection makefile for: trac-email2trac
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	email2trac
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	ftp://ftp.sara.nl/pub/outgoing/
PKGNAMEPREFIX=	trac-

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Convert email to trac tickets

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

OPTIONS=	POSTFIX "Configure suid script for postfix" OFF

TRACUSER?=	${WWWOWN}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-trac-user=${TRACUSER} --with-mta-user=${MTAUSER}
USE_PYTHON=	yes

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL README

.include <bsd.port.pre.mk>

.if defined(WITH_POSTFIX)
MTAUSER?=	nobody
.else
MTAUSER?=	mailnull
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/delete_spam.py ${PREFIX}/bin/delete_spam
	@${INSTALL_SCRIPT} ${WRKSRC}/email2trac.py ${PREFIX}/bin/email2trac
	@${INSTALL} ${COPY} ${STRIP} ${_BINOWNGRP} -m 4111 \
	    ${WRKSRC}/run_email2trac ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/email2trac.conf \
	    ${PREFIX}/etc/email2trac.conf.sample
	@if [ ! -e ${PREFIX}/etc/email2trac.conf ]; then \
		${CP} -p ${PREFIX}/etc/email2trac.conf.sample \
		    ${PREFIX}/etc/email2trac.conf ; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
