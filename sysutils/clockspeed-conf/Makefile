# New ports collection makefile for:	clockspeed-conf
# Date created:		10 April 2003
# Whom:			Patrick Atamaniuk <atamaniuk at frobs.net>
#
# $FreeBSD$
#

PORTNAME=	clockspeed-conf
PORTVERSION=	0.4.5
CATEGORIES=	sysutils
MASTER_SITES=	http://foo42.de/distfiles/

MAINTAINER=	atamaniuk-ports@frobs.net
COMMENT=	Supervise scripts for clockspeed to use daemontools

RUN_DEPENDS=	supervise:${PORTSDIR}/sysutils/daemontools \
		clockspeed:${PORTSDIR}/sysutils/clockspeed

MAN8=		clockspeed-conf.8 taiclockd-conf.8
DOCS=		COPYRIGHT README TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${ECHO_MSG} "***"
	@${ECHO_MSG} "*** Type 'make ids' to create user/group IDs"
	@${ECHO_MSG} "***"

ids:
	@${SH} ${FILESDIR}/create_ids.sh

.include <bsd.port.mk>
