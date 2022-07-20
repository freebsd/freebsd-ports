PORTNAME=	openlldp
DISTVERSION=	0.4alpha
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Link Layer Discovery Protocol daemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes

USE_RC_SUBR=	lldpd
PLIST_FILES=	sbin/lldpd bin/lldpneighbors man/man8/lldpd.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS =/CFLAGS +=/g' \
		${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lldpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/lldpneighbors ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/lldpd.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
