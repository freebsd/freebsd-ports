# New ports collection makefile for:	milter-callback
# Date created:				10 Feb 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	milter-callback
PORTVERSION=	1.5.7
CATEGORIES=	mail
MASTER_SITES=	http://unix.zhegan.in/distfiles/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Milter to perform a envelope-from sender verification on target MX

USE_BZIP2=	yes
USE_RC_SUBR=	milter-callback

SUB_FILES=	pkg-message
MAN8=		milter-callback.8

# make sure flat distfile gets extracted in ${WRKSRC}
EXTRACT_AFTER_ARGS=	| (${MKDIR} ${WRKSRC}; ${TAR} -xf - --no-same-owner \
				--no-same-permissions -C ${WRKSRC})

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" \
		${WRKSRC}/${PORTNAME}.c
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/var/tmp/|/var/run/|' \
		${WRKSRC}/${PORTNAME}.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MANPREFIX}/man/man8

	${MKDIR} ${PREFIX}/etc/mail
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf \
		${PREFIX}/etc/mail/${PORTNAME}.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
