# Created by: kiesel
# $FreeBSD$

PORTNAME=	reoback
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Release%203
EXTRACT_SUFX=	_r3.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple but flexible ftp/nfs backup script

RUN_DEPENDS=	p5-Net>=0:${PORTSDIR}/net/p5-Net

NO_BUILD=	yes
USES=		perl5

pre-install:
		cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/home/sforge/reoback/settings.conf,${PREFIX}/etc/reoback/settings.conf,g' ${WRKSRC}/run_reoback.sh
		cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/home/sforge/reoback/reoback.pl,${PREFIX}/bin/reoback.pl,g' ${WRKSRC}/run_reoback.sh
		cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,^#!/usr/bin/perl -W,#!/usr/bin/perl -w,g' reoback.pl

do-install:
		${INSTALL_SCRIPT}	${WRKSRC}/reoback.pl ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_SCRIPT}	${WRKSRC}/run_reoback.sh ${STAGEDIR}${PREFIX}/bin/
		${MKDIR}		${STAGEDIR}${PREFIX}/etc/reoback
		${INSTALL_DATA}		${WRKSRC}/conf/settings.conf ${STAGEDIR}${PREFIX}/etc/reoback/settings.conf.dist
		${INSTALL_DATA}		${WRKSRC}/conf/files.conf ${STAGEDIR}${PREFIX}/etc/reoback/files.conf.dist
		${INSTALL_MAN}		${WRKSRC}/docs/man/reoback.1.gz ${STAGEDIR}${PREFIX}/man/man1/
		${INSTALL_MAN}		${WRKSRC}/docs/man/reoback.pl.1.gz ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
