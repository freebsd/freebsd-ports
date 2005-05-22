# New ports collection makefile for:	freevrrpd
# Date created:				Tue Jan 29 18:44:25 EST 2002
# Whom:					Sebastien Petit <spe@bsdfr.org>
#
# $FreeBSD$
#

PORTNAME=	freevrrpd
PORTVERSION=	0.9.2
CATEGORIES=	net
MASTER_SITES=	http://www.b0l.org/download/ \
		${MASTER_SITE_LOCAL:S/$/:freebsd/g}
MASTER_SITE_SUBDIR=	flz/freevrrpd/:freebsd
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:DEFAULT,freebsd

MAINTAINER=	spe@b0l.org
COMMENT=	This a VRRP RFC2338 Compliant implementation under FreeBSD

MAN8=		freevrrpd.8

MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/freevrrpd ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/freevrrpd.conf.sample ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${WRKSRC}/freevrrpd.sh.sample ${PREFIX}/etc/rc.d
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
