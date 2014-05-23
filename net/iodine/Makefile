# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iodine
PORTVERSION=	0.6.0r1
CATEGORIES=	net
MASTER_SITES=	http://code.kryo.se/iodine/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	${PORTNAME}-0.6.0-rc1

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Tunnel IPv4 data through a DNS server

LICENSE=	BSD

PLIST_FILES=	bin/iodine sbin/iodined man/man8/iodine.8.gz man/man8/iodined.8.gz

PORTDOCS=	CHANGELOG README TODO

MAN8=		iodine.8
MLINKS=		iodine.8 iodined.8

USE_RC_SUBR=	iodined

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodine ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodined ${STAGEDIR}${PREFIX}/sbin
.for m in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/${m} ${STAGEDIR}${MANPREFIX}/man/man8
.endfor
	${GZIP_CMD} ${STAGEDIR}${MANPREFIX}/man/man8/iodine.8
	${LN} -s iodine.8.gz ${STAGEDIR}${MANPREFIX}/man/man8/iodined.8.gz
.if !defined(PORT_OPTIONS:MDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
