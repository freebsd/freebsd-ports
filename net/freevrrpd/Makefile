# New ports collection makefile for:	freevrrpd
# Date created:				Tue Jan 29 18:44:25 EST 2002
# Whom:					Sebastien Petit <spe@bsdfr.org>
#
# $FreeBSD$
#

PORTNAME=	freevrrpd
PORTVERSION=	0.8.3a
CATEGORIES=	net
MASTER_SITES=	http://www.bsdshell.net/download/

MAINTAINER=	spe@bsdfr.org

MAN8=		freevrrpd.8

MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/freevrrpd ${PREFIX}/libexec
	@${INSTALL_DATA} ${WRKSRC}/freevrrpd.conf.sample ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKSRC}/freevrrpd.conf.sample \
		${PREFIX}/etc/freevrrpd.conf
	@${INSTALL_SCRIPT} ${WRKSRC}/freevrrpd.sh.sample ${PREFIX}/etc/rc.d
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
