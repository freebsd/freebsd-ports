# ex:ts=8
# New ports collection makefile for:	nylon
# Date created:			Jun 11, 2001
# Whom:				William Ward <William.Ward@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	nylon
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/nylon/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Unix SOCKS 4 and 5 proxy server

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

GNU_CONFIGURE=	yes
# Necessary for $PREFIX to work:
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE}

MAN1=		nylon.1

PLIST_FILES=	bin/nylon etc/nylon.conf.sample etc/rc.d/nylon.sh

post-extract:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/nylon.sh.in > ${WRKSRC}/nylon.sh

post-install:
	${INSTALL_DATA} ${FILESDIR}/nylon.conf ${PREFIX}/etc/nylon.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/nylon.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
