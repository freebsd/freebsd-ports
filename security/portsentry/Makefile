# New ports collection makefile for:	sentry
# Date created:		3 January 1998
# Whom:			chris@still.whet.org
#
# $FreeBSD$
#

PORTNAME=	portsentry
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	SF/sentrytools/${PORTNAME}%201.x/${PORTNAME}-${PORTVERSION}

MAINTAINER=	glen.j.barber@gmail.com
COMMENT=	Port scan detection and active defense

SUB_FILES=	portsentry.sh
ALL_TARGET=	freebsd
CFLAGS+=	-DPREFIX=\"${PREFIX}\"
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
WRKSRC=		${WRKDIR}/portsentry_beta

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/psionic/portsentry,${PREFIX}/etc,g' \
		${WRKSRC}/portsentry.conf ${WRKSRC}/portsentry_config.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/portsentry.conf ${PREFIX}/etc/portsentry.conf.default
	${INSTALL_DATA} ${WRKSRC}/portsentry.ignore ${PREFIX}/etc/portsentry.ignore.default
	${INSTALL_PROGRAM} ${WRKSRC}/portsentry ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/portsentry.sh ${PREFIX}/etc/rc.d/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.install ${WRKSRC}/README.methods ${WRKSRC}/README.stealth \
	  ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
