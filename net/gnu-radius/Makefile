# New ports collection makefile for:	gnu-radius
# Date created:		13 Jul 2001
# Whom:			lance@evitel.net
#
# $FreeBSD$

PORTNAME=	gnu-radius
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	radius
DISTNAME=       radius-${PORTVERSION}

MAINTAINER=	lance@merlin.net.ua
COMMENT=	GNU RADIUS server

#MAKEFILE=	Makefile

CONFLICTS=	freeradius-0.* openradius-0.* radiusd-cistron-1.*
USE_SUBMAKE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	# empty

MAN1=		radgrep.1 radlast.1 raduse.1 radwho.1
MAN8=		builddbm.8 radctl.8 radiusd.8 radping.8 radzap.8
MANCOMPRESSED=	no

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		CURDIR="${.CURDIR}" \
		MKDIR="${MKDIR}"

STARTUP_FILE=	${PREFIX}/etc/rc.d/gnu-radius.sh

.if defined(BATCH)
CONFIGURE_ARGS+=--with-include-path="${LOCALBASE}/include/" \
		--with-lib-path="${LOCALBASE}/lib/"
.else
post-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
.endif

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

post-install:
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=g" ${FILESDIR}/gnu-radius.sh.tmpl \
		> ${PREFIX}/etc/rc.d/gnu-radius.sh
	@${CHMOD} 550 ${PREFIX}/etc/rc.d/gnu-radius.sh
	@${CHOWN} root:wheel ${PREFIX}/etc/rc.d/gnu-radius.sh

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
