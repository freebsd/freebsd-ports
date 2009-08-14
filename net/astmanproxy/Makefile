# New ports collection makefile for:	astmanproxy
# Date created:		1 November 2007
# Whom:			ditesh@gathani.org
#
# $FreeBSD$
#

PORTNAME=	astmanproxy
PORTVERSION=	1.21
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.popvox.com/
DISTFILES=	astmanproxy-latest.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-threaded proxy server for Asterisk

RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

BROKEN=		does not fetch

USE_OPENSSL=	yes
USE_GMAKE=	yes

ALL_TARGET=	astmanproxy

post-patch:
	${REINPLACE_CMD} -e 's|^CONFDIR:.*|CONFDIR := ${PREFIX}/etc/asterisk|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|^CONFDIR_REAL.*|CONFDIR_REAL := ${PREFIX}/etc/asterisk|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|^PERMDIR:.*|PERMDIR:= ${PREFIX}/etc/asterisk|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|^PERMDIR_REAL.*|PERMDIR_REAL := ${PREFIX}/etc/asterisk|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|^LIBDIR.*|LIBDIR := ${PREFIX}/lib/asterisk|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|^BINDIR.*|BINDIR := ${PREFIX}/sbin|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|MKTEMP=.*|MKTEMP=/usr/bin/mktemp|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|LOGDIR=/var/log/asterisk|LOGDIR=/var/log|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|-ldl ||' ${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${PREFIX}/etc/asterisk

post-install:
	@${INSTALL_DATA} ${WRKSRC}/configs/astmanproxy.conf ${PREFIX}/etc/asterisk/astmanproxy.conf.sample
	@[ -f ${PREFIX}/etc/asterisk/astmanproxy.conf ] || \
	 ${INSTALL_DATA} ${WRKSRC}/configs/astmanproxy.conf ${PREFIX}/etc/asterisk/astmanproxy.conf
	@${INSTALL_DATA} ${WRKSRC}/configs/astmanproxy.users ${PREFIX}/etc/asterisk/astmanproxy.users.sample
	@[ -f ${PREFIX}/etc/asterisk/astmanproxy.users ] || \
	 ${INSTALL_DATA} ${WRKSRC}/configs/astmanproxy.users ${PREFIX}/etc/asterisk/astmanproxy.users
	@${INSTALL_DATA} ${WRKSRC}/configs/ssl.conf ${PREFIX}/etc/asterisk/proxy-ssl.conf.sample
	@[ -f ${PREFIX}/etc/asterisk/proxy-ssl.conf ] || \
	 ${INSTALL_DATA} ${WRKSRC}/configs/ssl.conf ${PREFIX}/etc/asterisk/proxy-ssl.conf

.include <bsd.port.mk>
