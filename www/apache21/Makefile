# New ports collection makefile for:    apache HTTPD
# Version required:     1.0.5
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.10 1996/05/19 22:21:42 ache Exp $
#

DISTNAME=       apache_1.0.5
PKGNAME=        apache-1.0.5
CATEGORIES+=	www
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		ftp://www.apache.org/apache/dist/contrib/modules/
DISTFILES=      ${DISTNAME}.tar.gz mod_env.c

MAINTAINER=	pst@freebsd.org

EXTRACT_ONLY=   ${DISTNAME}.tar.gz

post-extract:
	cp ${DISTDIR}/mod_env.c ${WRKSRC}/src

.include <bsd.port.mk>
