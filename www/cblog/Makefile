# New ports collection makefile for:	cblog
# Date created:		2010-07-16
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cblog
PORTVERSION=	0.1.1
CATEGORIES=	www
MASTER_SITES=	http://cloud.github.com/downloads/bapt/cblog/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Simple weblog in C using markdown

BUILD_DEPENDS=	${LOCALBASE}/lib/libneo_cs.a:${PORTSDIR}/www/clearsilver \
		${LOCALBASE}/lib/libcdb.a:${PORTSDIR}/databases/tinycdb
LIB_DEPENDS=	fcgi.0:${PORTSDIR}/www/fcgi

LICENSE=	BSD

PLIST_FILES=	libexec/cblog.fcgi \
		bin/cblogctl \
		etc/cblog.conf.sample

MAN1=		cblog.fcgi.1

post-patch:
	@${REINPLACE_CMD} "s#^INCLUDES=.*#INCLUDES=-I${LOCALBASE}/include#g" ${WRKSRC}/config.mk
	@${REINPLACE_CMD} "s#^LIBDIR=.*#LIBDIR=-L${LOCALBASE}/lib#g" ${WRKSRC}/config.mk
	@${REINPLACE_CMD} "s#^CSINCLUDES=.*#CSINCLUDES=-I${LOCALBASE}/include/ClearSilver#g" ${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cblog.cgi ${PREFIX}/libexec/cblog.fcgi
	${INSTALL_PROGRAM} ${WRKSRC}/cblogctl ${PREFIX}/bin/cblogctl
	${INSTALL_DATA} ${WRKSRC}/samples/cblog.conf ${PREFIX}/etc/cblog.conf.sample
	${INSTALL_MAN} ${WRKSRC}/cgi/cblog.cgi.1 ${MANPREFIX}/man/man1/cblog.fcgi.1

.include <bsd.port.mk>
