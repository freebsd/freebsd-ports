# Created by: Sebastien Petit <spe@phear.org>
# $FreeBSD$

PORTNAME=	freevrrpd
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	http://opensource.kewego.com/freevrrpd/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:DEFAULT,freebsd

MAINTAINER=	spe@phear.org
COMMENT=	This a VRRP RFC2338 Compliant implementation under FreeBSD

MAN8=		freevrrpd.8

MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/freevrrpd ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/freevrrpd.conf.sample ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${WRKSRC}/rc.d/freevrrpd ${PREFIX}/etc/rc.d
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8

post-install:
	@${ECHO} ''
	@${CAT} ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.mk>
