# New ports collection makefile for:	srmt
# Date created:		Wed Jan 15 13:11:24 CET 2003
# Whom:			olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	srmt
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/
DISTNAME=	star-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Schily's enhanced rmt implementation

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKE_ENV=	MAKEPROG=${GMAKE} CCOM=${CC}
MAN1=		srmt.1

post-extract:
.if ${MACHINE_ARCH} != "i386" || ${CC} != "cc"
	@${LN} -sf i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${MACHINE_ARCH}-freebsd-${CC}.rul
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/default/rmt|${PREFIX}/etc/srmt.conf|g' ${WRKSRC}/rmt/rmt.c ${WRKSRC}/rmt/rmt.1
	@${REINPLACE_CMD} -e 's|!!PREFIX!!|${PREFIX}|g' ${WRKSRC}/rmt/rmt.1
	@${FIND} ${WRKSRC} -name \*.bak | ${XARGS} ${RM}

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/rmt/OBJ/${MACHINE_ARCH}-freebsd-${CC}/rmt \
		${PREFIX}/sbin/srmt
	@${INSTALL_MAN} ${WRKSRC}/rmt/rmt.1 ${MANPREFIX}/man/man1/srmt.1
	@${INSTALL_DATA} ${WRKSRC}/rmt/rmt.dfl ${PREFIX}/etc/srmt.conf.dist

	@if [ ! -f ${PREFIX}/etc/srmt.conf ]; then \
		${CP} -p ${PREFIX}/etc/srmt.conf.dist ${PREFIX}/etc/srmt.conf; \
	fi
	@${CHMOD} u+s ${PREFIX}/sbin/srmt

.include <bsd.port.mk>
