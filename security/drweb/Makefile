# New ports collection makefile for:   tas
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@urc.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb
PORTVERSION=	4.25
CATEGORIES=	security
MASTER_SITES=	http://www.drweb.ru/ftp/web_pub/
DISTNAME=	${PORTNAME}d-${PORTVERSION}-freebsd4
EXTRACT_SUFX=	.tgz

MAINTAINER=	anton@urc.ac.ru

NO_BUILD=	YES

DRWEB_PREFIX=	${PREFIX}/${PORTNAME}

do-install:
	-@${MKDIR} -v ${DRWEB_PREFIX}
	${TAR} -xvzf ${WRKSRC}/${DISTNAME}.tar.gz -C ${DRWEB_PREFIX} --exclude *.ini
	${TAR} -xvzOf ${WRKSRC}/${DISTNAME}.tar.gz drweb32.ini >${DRWEB_PREFIX}/drweb32.ini.sample
	${SED} 's#!!PREFIX!!#${DRWEB_PREFIX}#' < ${FILESDIR}/drwebd.sh >${WRKSRC}/drwebd.sh
	${INSTALL_SCRIPT} ${WRKSRC}/drwebd.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
