# New ports collection makefile for:   drweb
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

# Needed for update.pl
RUN_DEPENDS=    ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/mach/String/CRC32.pm:${PORTSDIR}/devel/p5-String-CRC32

DRWEB_PREFIX=	${PREFIX}/${PORTNAME}

do-install:
	-@${MKDIR} -v ${DRWEB_PREFIX}
	${TAR} -xzf ${WRKSRC}/${DISTNAME}.tar.gz -C ${DRWEB_PREFIX} --exclude *.ini
	${TAR} -xzOf ${WRKSRC}/${DISTNAME}.tar.gz drweb32.ini >${DRWEB_PREFIX}/drweb32.ini.sample
	${SED} 's#!!PREFIX!!#${DRWEB_PREFIX}#' < ${FILESDIR}/drwebd.sh >${WRKSRC}/drwebd.sh
	cd ${DRWEB_PREFIX}/update; patch -s < ${FILESDIR}/update-patch && ${RM} update.pl.orig
	${INSTALL_DATA} ${WRKSRC}/drwebd.sh ${PREFIX}/etc/rc.d/drwebd.sh-dist

.include <bsd.port.mk>
