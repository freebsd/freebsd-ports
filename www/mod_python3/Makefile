# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION=	3.0.1
CATEGORIES=	www python
MASTER_SITES=	http://www.apache.org/dist/httpd/%SUBDIR%/ \
		http://apache.mirrorcentral.com/dist/httpd/%SUBDIR%/ \
		http://apache.missouri.edu/dist/httpd/%SUBDIR%/ \
		http://ftp.epix.net/apache/dist/httpd/%SUBDIR%/ \
		ftp://ftp.digex.net/pub/packages/network/apache/httpd/%SUBDIR%/ \
		ftp://ftp.cuckoo.com/pub/mirrors/apache/dist/httpd/%SUBDIR%/
MASTER_SITE_SUBDIR=	modpython
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/apache2/httpd.h:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${LOCALBASE}/include/apache2/httpd.h:${PORTSDIR}/www/apache2

USE_PYTHON=	yes

APXS?=		${LOCALBASE}/sbin/apxs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}" --with-python="${PYTHON_CMD}"
MAKE_ENV=	EXPR_COMPAT=yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
