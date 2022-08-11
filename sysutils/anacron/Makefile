PORTNAME=	anacron
PORTVERSION=	2.3
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	dz@426.ch
COMMENT=	Schedules periodic jobs on systems that are not permanently up

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME} COMMENT="${COMMENT}"

post-patch:
.for f in Makefile ${PORTNAME}.8 ${PORTNAME}tab.5
	@${REINPLACE_CMD} -e 's|\(/etc/${PORTNAME}tab\)|${PREFIX}\1|' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's|^CFLAGS = .*||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}tab.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}tab.sample ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}/var/spool/${PORTNAME}

.include <bsd.port.mk>
