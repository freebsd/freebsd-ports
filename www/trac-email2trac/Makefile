# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	email2trac
PORTVERSION=	2.6.2
CATEGORIES=	www devel python
MASTER_SITES=	ftp://ftp.sara.nl/pub/outgoing/
PKGNAMEPREFIX=	trac-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert email to trac tickets

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

OPTIONS_DEFINE=	POSTFIX
POSTFIX_DESC=	Configure suid script for postfix

TRACUSER?=	${WWWOWN}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-trac-user=${TRACUSER} --with-mta-user=${MTAUSER}
USE_PYTHON=	2

PORTDOCS=	AUTHORS ChangeLog INSTALL README

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPOSTFIX}
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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
