# New ports collection makefile for:   reoback
# Date created:        19 April 2003
# Whom:                kiesel
#
# $FreeBSD$
#

PORTNAME=	reoback
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Release%203
EXTRACT_SUFX=	_r3.tar.gz

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Simple but flexible ftp/nfs backup script

RUN_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net

NO_BUILD=	yes
USE_PERL5=	yes

MAN1=		reoback.1 reoback.pl.1
MANCOMPRESSED=	yes

pre-install:
		cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/home/sforge/reoback/settings.conf,${PREFIX}/etc/reoback/settings.conf,g' ${WRKSRC}/run_reoback.sh
		cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/home/sforge/reoback/reoback.pl,${PREFIX}/bin/reoback.pl,g' ${WRKSRC}/run_reoback.sh
		cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,^#!/usr/bin/perl -W,#!/usr/bin/perl -w,g' reoback.pl

do-install:
		${INSTALL_SCRIPT}	${WRKSRC}/reoback.pl ${PREFIX}/bin/
		${INSTALL_SCRIPT}	${WRKSRC}/run_reoback.sh ${PREFIX}/bin/
		${MKDIR}		${PREFIX}/etc/reoback
		${INSTALL_DATA}		${WRKSRC}/conf/settings.conf ${PREFIX}/etc/reoback/settings.conf.dist
		${INSTALL_DATA}		${WRKSRC}/conf/files.conf ${PREFIX}/etc/reoback/files.conf.dist
		${INSTALL_MAN}		${WRKSRC}/docs/man/reoback.1.gz ${PREFIX}/man/man1/
		${INSTALL_MAN}		${WRKSRC}/docs/man/reoback.pl.1.gz ${PREFIX}/man/man1/

.include <bsd.port.mk>
