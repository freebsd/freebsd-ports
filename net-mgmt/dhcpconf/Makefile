# New ports collection makefile for:	dhcp-conf
# Version required:	0.7.0
# Date created:		20 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	dhcp-conf
PKGNAME=	dhcpconf-${VERSION}
CATEGORIES=	net sysutils
MASTER_SITES=	http://members.xoom.com/vschade/dhcp-conf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		newt.0:${PORTSDIR}/devel/newt

ALL_TARGET=	${DISTNAME}
VERSION=	0.7.0
WRKSRC=		${WRKDIR}/${DISTNAME}_${VERSION}
MAKE_ENV+=	PCFLAGS="${CFLAGS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dhcp-conf ${PREFIX}/sbin/dhcpconf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/dhcpconf
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/dhcpconf
.endif

.include <bsd.port.mk>
