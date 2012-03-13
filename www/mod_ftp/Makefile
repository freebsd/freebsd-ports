# New ports collection makefile for:	mod_ftp
# Date created:				June 21, 2011 Oct  5
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_ftp
DISTVERSION=	0.9.6-beta
CATEGORIES=	www ftp
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=httpd/mod_ftp

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Serve web-server's content via FTP

MAKE_JOBS_SAFE=	yes

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
USE_APACHE=	20+
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=configure.apxs
CONFIGURE_ENV+=	APXS="${APXS}"

post-install:
	@${CAT} ${PKGMESSAGE}
	${TEST} -e ${PREFIX}/${APACHEETCDIR}/extra/ftpd.conf ||	\
	    ${CP} -p ${PREFIX}/${APACHEETCDIR}/extra/ftpd.conf.dist	\
		${PREFIX}/${APACHEETCDIR}/extra/ftpd.conf

.include <bsd.port.mk>
