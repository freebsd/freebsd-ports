# New ports collection makefile for:	f-prot
# Date created:			4 June 2003
# Whom:				Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	prot
PORTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.f-prot.com/pub/bsd/
PKGNAMEPREFIX=	f-
DISTNAME=	fp-freebsd-ws-${PORTVERSION}

MAINTAINER=	tim@bishnet.net
COMMENT=	F-Prot Antivirus for BSD Workstations

RUN_DEPENDS=	${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww

NO_PACKAGE=	Free for personal use only
NO_CDROM=	Free for personal use only
RESTRICTED=	Free for personal use only

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}
NO_BUILD=	yes

MAN1=		f-prot.1

do-install:
	cd ${WRKDIR} && ${TAR} -cf - f-prot | ${TAR} -xf - -C ${PREFIX}
	${INSTALL_SCRIPT} ${WRKSRC}/f-prot.sh ${PREFIX}/bin/f-prot
	${INSTALL_MAN} ${WRKSRC}/man_pages/f-prot.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
