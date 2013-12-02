# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsnmptools
PORTVERSION=	0.0.20100516
CATEGORIES=	net-mgmt
MASTER_SITES=	http://people.freebsd.org/~syrinx/snmp/ CENKES
DISTNAME=	bsnmptools-20100516-01
EXTRACT_SUFX=	.tar

MAINTAINER=	unixmania@gmail.com
COMMENT=	Snmp client tools

LICENSE=	BSD

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 900028
IGNORE=		client tools (including SNMPv3 support) are part of the base system
.endif

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/bsnmptools/usr.sbin/bsnmpd/tools
MAKE_ARGS=	SHLIB_MAJOR=0 INCLUDEDIR=${PREFIX}/include LIBDIR=${PREFIX}/lib \
		MANDIR=${MANPREFIX}/man/man NO_MANCOMPRESS=yes BINDIR=${PREFIX}/bin \
		NO_PROFILE=yes
PLIST_FILES=	${BIN_FILES:S,^,bin/,} \
		lib/lib${PORTNAME}.a lib/lib${PORTNAME}.so lib/lib${PORTNAME}.so.0 \
		${BIN_FILES:S,^,man/man1/,:S,$,.1.gz,}
BIN_FILES=	bsnmpget bsnmpset bsnmpwalk

post-patch:
	@${REINPLACE_CMD} -e 's|$${DESTDIR}/usr/bin|$${STAGEDIR}$${BINDIR}|g' ${WRKSRC}/bsnmptools/Makefile

.include <bsd.port.post.mk>
