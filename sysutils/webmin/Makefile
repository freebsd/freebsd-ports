# New ports collection makefile for:	webmin
# Version required:	0.64
# Date created:		Do  19 Nov 1998 21:13:55 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

DISTNAME=	webmin-0.73
CATEGORIES=	sysutils
MASTER_SITES=	http://www.webmin.com/webmin/download/

MAINTAINER=	andreas@FreeBSD.org

NO_BUILD=	yes
IS_INTERACTIVE=	yes
USE_PERL5=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/webmin
	${CP} -r ${WRKSRC}/* ${PREFIX}/lib/webmin
	@cd ${PREFIX}/lib/webmin && find . -name "*.orig" -print | xargs ${RM}
	@cd ${PREFIX}/lib/webmin && ./setup.sh

.include <bsd.port.mk>
