# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	milter-callback
PORTVERSION=	1.6.0
CATEGORIES=	mail
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Milter to perform a envelope-from sender verification on target MX

LICENSE=	GPLv3

LIB_DEPENDS+=	spf2:${PORTSDIR}/mail/libspf2

USE_XZ=		yes
USE_RC_SUBR=	milter-callback

SUB_FILES=	pkg-message
MAN8=		milter-callback.8

MAKE_ENV+=	WITH_SPF=yes
MAKE_JOBS_SAFE=	yes

.if ${CC} == "clang" || ${CXX} == "clang++"
BROKEN=	does not build with clang, uses nested functions
.endif

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
