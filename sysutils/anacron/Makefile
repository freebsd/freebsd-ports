# Created by: Derik van Zuetphen <dz@426.ch>
# $FreeBSD$

PORTNAME=	anacron
PORTVERSION=	2.3
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	dz@426.ch
COMMENT=	Schedules periodic jobs on systems that are not permanently up

USES=		gmake
USE_RC_SUBR=	anacron
SUB_FILES=	pkg-message

post-patch:
.for f in Makefile anacron.8 anacrontab.5
	@${REINPLACE_CMD} -e 's|\(/etc/anacrontab\)|${PREFIX}\1|' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's|^CFLAGS = .*||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/anacron ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/anacron.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/anacrontab.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	${INSTALL_DATA} ${FILESDIR}/anacrontab.sample ${STAGEDIR}${PREFIX}/etc

post-install:
	[ -d ${STAGEDIR}/var/spool/anacron ] || ${MKDIR} ${STAGEDIR}/var/spool/anacron

.include <bsd.port.mk>
