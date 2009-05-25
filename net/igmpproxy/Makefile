# New ports collection makefile for:  igmpproxy
# Date created:	       5 January 2009
# Whom:		       asami
#
# $FreeBSD$
#

PORTNAME=	igmpproxy
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}-beta2

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Multicast forwarding IGMP proxy

HOMEPAGE=	http://igmpproxy.sourceforge.net/

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src

USE_RC_SUBR=	igmpproxy
USE_GMAKE=	yes

MAN5=		igmpproxy.conf.5
MAN8=		igmpproxy.8

PLIST_FILES=	sbin/igmpproxy \
		etc/igmpproxy.conf.sample

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/igmpproxy ${PREFIX}/sbin/
	@${INSTALL_DATA} ${WRKSRC}/src/igmpproxy.conf ${PREFIX}/etc/igmpproxy.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/doc/igmpproxy.8 ${PREFIX}/man/man8/
	@${INSTALL_MAN} ${WRKSRC}/doc/igmpproxy.conf.5 ${PREFIX}/man/man5/

.include <bsd.port.mk>
