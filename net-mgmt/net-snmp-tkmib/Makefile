# New ports collection makefile for:	net-snmp-tkmib
# Date created:				4 April 2002
# Whom:					kuriyama
#
# $FreeBSD$
#

PORTNAME=	ucd-snmp-tkmib
PORTVERSION=	4.2.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ucd-snmp.ucdavis.edu/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/ \
		ftp://ftp.win.ne.jp/pub/network/snmp/ucd-snmp/
MASTER_SITE_SUBDIR=	net-snmp
DISTNAME=	ucd-snmp-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org

RUN_DEPENDS=	${SITE_PERL}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk \
		${SITE_PERL}/SNMP.pm:${PORTSDIR}/net/p5-SNMP

WRKSRC=		${WRKDIR}/ucd-snmp-${PORTVERSION}
NO_BUILD=	yes

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/local/tkmib ${PREFIX}/bin

.include <bsd.port.mk>
