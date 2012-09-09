# $FreeBSD$

PORTNAME=	milter-callback
PORTVERSION=	1.5.10
CATEGORIES=	mail
MASTER_SITES=	http://unix.zhegan.in/distfiles/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Milter to perform a envelope-from sender verification on target MX

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_RC_SUBR=	milter-callback

SUB_FILES=	pkg-message
MAN8=		milter-callback.8

# make sure flat distfile gets extracted in ${WRKSRC}
EXTRACT_AFTER_ARGS=	| (${MKDIR} ${WRKSRC}; ${TAR} -xf - --no-same-owner \
				--no-same-permissions -C ${WRKSRC})

OPTIONS_DEFINE=	SPF
SPF_DESC=	libspf support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSPF}
MAKE_ENV+=	WITH_SPF=yes
LIB_DEPENDS+=	spf2.3:${PORTSDIR}/mail/libspf2
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
