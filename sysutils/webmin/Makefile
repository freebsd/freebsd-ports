# New ports collection makefile for:	webmin
# Version required:	0.76
# Date created:		Do  19 Nov 1998 21:13:55 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

DISTNAME=	webmin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://www.webmin.com/webmin/download/

MAINTAINER=	andreas@FreeBSD.org

VERSION=	0.76
NO_BUILD=	yes
IS_INTERACTIVE=	yes
USE_PERL5=	yes

post-patch:
	${CP} ${WRKDIR}/webmin-${VERSION}/bind8/config-freebsd-3.0 \
	${WRKDIR}/webmin-${VERSION}/bind8/config-freebsd-3.1
	${CP} ${WRKDIR}/webmin-${VERSION}/bind8/config-freebsd-3.0 \
	${WRKDIR}/webmin-${VERSION}/bind8/config-freebsd-3.2
	${CP} ${WRKDIR}/webmin-${VERSION}/bind8/config-freebsd-3.0 \
	${WRKDIR}/webmin-${VERSION}/bind8/config-freebsd-3.3
	${CP} ${WRKDIR}/webmin-${VERSION}/bind8/config-freebsd-3.0 \
	${WRKDIR}/webmin-${VERSION}/bind8/config-freebsd-3.4

do-install:
	${MKDIR} ${PREFIX}/lib/webmin
	${CP} -r ${WRKSRC}/* ${PREFIX}/lib/webmin
	@cd ${PREFIX}/lib/webmin && find . -name "*.orig" -print | xargs ${RM}
	@cd ${PREFIX}/lib/webmin && ./setup.sh

.include <bsd.port.mk>
