# New ports collection makefile for: 	netqc
# Date created:		Sep 28 2001
# Whom:			Radoslav Vasilev <rvasilev@uni-svishtov.bg>
#
# $FreeBSD$
#

PORTNAME=	netqc
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://web.uni-svishtov.bg/netqc/

MAINTAINER=	rvasilev@uni-svishtov.bg
COMMENT=	Network Monitoring System based on Net-Snmp

LIB_DEPENDS=	snmp.4:${PORTSDIR}/net-mgmt/net-snmp4

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_MYSQL=	yes
DEFAULT_MYSQL_VER=	323
WANT_MYSQL_VER=		323
USE_REINPLACE=	yes
MAN1=		netqc.1
DOCFILES=	COPYING README

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,varargs.h,stdarg.h," ${WRKSRC}/poll.c

post-install:
		${INSTALL_DATA} ${WRKSRC}/conf ${PREFIX}/etc/netqc.conf.sample
.for file in ${MAN1}
		${INSTALL_MAN} ${WRKSRC}/${file} ${MANPREFIX}/man/man1/${file}
.endfor
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
