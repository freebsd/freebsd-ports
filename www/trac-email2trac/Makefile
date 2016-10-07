# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	email2trac
PORTVERSION=	2.9.0
CATEGORIES=	www devel python
MASTER_SITES=	ftp://ftp.sara.nl/pub/outgoing/
PKGNAMEPREFIX=	trac-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert email to trac tickets

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	tracd:www/trac

CONFLICTS_INSTALL?=	trac-email2trac-postfix-[0-9]*

OPTIONS_DEFINE=	POSTFIX DOCS
POSTFIX_DESC=	Configure suid script for postfix

TRACUSER?=	${WWWOWN}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-trac-user=${TRACUSER} --with-mta-user=${MTAUSER}
USES=		python:2

PORTDOCS=	AUTHORS ChangeLog INSTALL README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPOSTFIX}
MTAUSER?=	nobody
.else
MTAUSER?=	mailnull
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/delete_spam.py ${STAGEDIR}${PREFIX}/bin/delete_spam
	${INSTALL_SCRIPT} ${WRKSRC}/email2trac.py ${STAGEDIR}${PREFIX}/bin/email2trac
	${INSTALL_PROGRAM} \
	    ${WRKSRC}/run_email2trac ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/email2trac.conf \
	    ${STAGEDIR}${PREFIX}/etc/email2trac.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
