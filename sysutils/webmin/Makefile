# New ports collection makefile for:	webmin
# Version required:	0.64
# Date created:		Do  19 Nov 1998 21:13:55 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.5 1999/04/12 18:53:30 andreas Exp $
#

DISTNAME=	webmin-0.71
CATEGORIES=	sysutils
MASTER_SITES=	http://www.webmin.com/webmin/download/

MAINTAINER=	andreas@FreeBSD.ORG

NO_BUILD=	yes
IS_INTERACTIVE=	yes
USE_PERL5=	yes

pre-extract:
	@if [ -x ${PREFIX}/sbin/httpd ]; then \
	${ECHO_MSG} Good ! You seem to have apache webserver installed ...; \
	else \
	${ECHO_MSG} You need to install one of the different apache webservers; \
	${ECHO_MSG} Best would be apache13-modssl or apache13-php3 that can be; \
	${ECHO_MSG} configured to use modssl for better security as well; \
	exit 1; \
	fi

do-install:
	${MKDIR} ${PREFIX}/lib/webmin
	${CP} -r ${WRKSRC}/* ${PREFIX}/lib/webmin
	@cd ${PREFIX}/lib/webmin && find . -name "*.orig" -print | xargs ${RM}
	@cd ${PREFIX}/lib/webmin && ./setup.sh

.include <bsd.port.mk>
