# New ports collection makefile for:	netsaint-plugins
# Date created:				Wed 12 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	netsaint-plugins
PORTVERSION=	1.2.9.4
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	netsaintplug
DISTNAME=	${PORTNAME}-1.2.9-4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugins for netsaint

BROKEN=		Broken pkg-plist

USE_SUBMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sbindir=${PREFIX}/share/netsaint/sbin \
		--libexecdir=${PREFIX}/libexec/netsaint \
		--datadir=${PREFIX}/share/netsaint \
		--sysconfdir=${PREFIX}/etc/netsaint \
		--localstatedir=${PREFIX}/var/netsaint
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		MKDIR="${MKDIR}"
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213
USE_GMAKE=	yes

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

post-patch:
	@${FIND} ${WRKSRC}/plugins-scripts/ -type f -perm -+x | ${XARGS} -n1 \
		${REINPLACE_CMD} -e "s,/bin/diff,/usr/bin/diff,g" \
			-e "s,/bin/sed,/usr/bin/sed,g" \
			-e "s,/bin/tail,/usr/bin/tail,g" \
			-e "s,/bin/grep,/usr/bin/grep,g"

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
