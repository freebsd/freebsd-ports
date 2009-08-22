# New ports collection makefile for:	net-snmp-tkmib
# Date created:				4 April 2002
# Whom:					kuriyama
#
# $FreeBSD$
#

PORTNAME=	ucd-snmp-tkmib
PORTVERSION=	4.2.7.1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/net-snmp/ucd-snmp/${PORTVERSION}%20source%20code
DISTNAME=	ucd-snmp-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	An extendable SNMP implementation (tkmib part)

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk \
		${SITE_PERL}/${PERL_ARCH}/SNMP.pm:${PORTSDIR}/net-mgmt/p5-SNMP

WRKSRC=		${WRKDIR}/ucd-snmp-${PORTVERSION}
NO_BUILD=	yes
USE_PERL5=	yes
PLIST_FILES=	bin/tkmib

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/local/tkmib ${PREFIX}/bin

.include <bsd.port.mk>
