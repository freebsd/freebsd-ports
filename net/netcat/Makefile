# ex:ts=8
# Ports collection makefile for:  netcat
# Date created:			  Thur Nov 21, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	netcat
PORTVERSION=	1.10
PORTREVISION=	3
CATEGORIES=	net ipv6
MASTER_SITES=	SF/${DISTNAME}/unix%20netcat%20${PORTVERSION}%20by%20_Hobbit_/%5BUnnamed%20release%5D
DISTNAME=	nc${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

#PATCH_SITES=	ftp://sith.mimuw.edu.pl/pub/users/baggins/IPv6/
PATCH_SITES=	${MASTER_SITE_GENTOO}
PATCH_SITE_SUBDIR=	distfiles
PATCHFILES=	nc-v6-20000918.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple utility which reads and writes data across network connections

OPTIONS_DEFINE=	IPV6 TELNET GAPING DOCS
OPTIONS_DEFAULT=IPV6 TELNET GAPING
TELNET_DESC=	Enable TELNET support
GAPING_DESC=	Enable GAPING_SECURITY_HOLE support

NO_WRKSUBDIR=	yes

CFLAGS+=	-D${OPSYS:U}
LDFLAGS+=	-static

MAN1=		netcat.1
PORTDOCS=	README
PLIST_FILES=	bin/netcat

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CFLAGS+=	-DINET6
.endif

.if ${PORT_OPTIONS:MTELNET}
CFLAGS+=	-DTELNET
.endif

.if ${PORT_OPTIONS:MGAPING}
CFLAGS+=	-DGAPING_SECURITY_HOLE
.endif

post-patch:
	@${SED} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' ${FILESDIR}/nc.1 \
		> ${WRKDIR}/${PORTNAME}.1

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME} ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
