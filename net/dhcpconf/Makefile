# New ports collection makefile for:	dhcp-conf
# Date created:		20 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	dhcpconf
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	net sysutils
MASTER_SITES=	http://members.xoom.com/vschade/dhcp-conf/
DISTNAME=	dhcp-conf
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm \
		newt.51:${PORTSDIR}/devel/newt

ALL_TARGET=	${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}_${PORTVERSION}
MAKE_ENV+=	PCFLAGS="${CFLAGS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dhcp-conf ${PREFIX}/sbin/dhcpconf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
