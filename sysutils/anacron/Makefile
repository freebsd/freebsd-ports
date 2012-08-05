# New ports collection makefile for:   anacron
# Date created:        15 Jul 2003
# Whom:                Derik van Zuetphen <dz@426.ch>
#
# $FreeBSD$
#

PORTNAME=	anacron
PORTVERSION=	2.3
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	dz@426.ch
COMMENT=	Schedules periodic jobs on systems that are not permanently up

MAN8=		anacron.8
MAN5=		anacrontab.5
USE_GMAKE=	yes
USE_RC_SUBR=	anacron
SUB_FILES=	pkg-message

post-patch:
.for f in Makefile anacron.8 anacrontab.5
	@${REINPLACE_CMD} -e 's|\(/etc/anacrontab\)|${PREFIX}\1|' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's|^CFLAGS = .*||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/anacron ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/anacron.8 ${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/anacrontab.5 ${MAN5PREFIX}/man/man5
	${INSTALL_DATA} ${FILESDIR}/anacrontab.default ${PREFIX}/etc
	[ -f ${PREFIX}/etc/anacrontab ] || ${INSTALL_DATA} ${FILESDIR}/anacrontab.default ${PREFIX}/etc/anacrontab
	${MKDIR} /var/spool/anacron

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
