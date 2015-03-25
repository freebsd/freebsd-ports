# Created by: Sebastien Petit <spe@phear.org>
# $FreeBSD$

PORTNAME=	freevrrpd
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://opensource.kewego.com/freevrrpd/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:DEFAULT,freebsd

MAINTAINER=	spe@phear.org
COMMENT=	VRRP RFC2338 Compliant implementation under FreeBSD

MAKE_ENV=	PTHREAD_LIBS="-lpthread"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freevrrpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/freevrrpd.conf.sample \
		${STAGEDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/freevrrpd \
		${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 \
		${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
