# New ports collection makefile for:	mod_bandwidth
# Date created:				2 July 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

#Orignal locations: ftp://ftp.cohprog.com/pub/apache/module/1.3.0/mod_bandwidth.c
#                   ftp://ftp.cohprog.com/pub/apache/module/cleanlink.pl

PORTNAME=	mod_bandwidth
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cohprog.com/pub/apache/module/:1 \
		ftp://ftp.cohprog.com/pub/apache/module/
MASTER_SITE_SUBDIR=1.3.0/:1
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
EXTRACT_SUFX=	# none
## source files are only as .c and .pl available from upstream
DISTFILES=	mod_bandwidth.c:1 cleanlink.pl
DIST_SUBDIR=	apache
EXTRACT_ONLY=

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Bandwidth management module for the Apache webserver

MAKE_JOBS_SAFE=	yes

CONFLICTS=	apache-contrib-1.*

USE_PERL5=	YES
USE_APACHE=	1.3
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES+=	sbin/cleanlink.pl

post-extract:
.for i in ${DISTFILES:C/:1//}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}/
.endfor

post-install:
	@${ECHO} "@unexec ${SED} -i '' '/AddModule.*mod_bandwidth.c/d' %D/etc/apache/httpd.conf" >> ${TMPPLIST}
	@${INSTALL_SCRIPT} ${WRKSRC}/cleanlink.pl ${LOCALBASE}/sbin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
