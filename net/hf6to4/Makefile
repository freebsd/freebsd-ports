# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	hf6to4
PORTVERSION=	1.5
CATEGORIES=	net ipv6
MASTER_SITES=	http://cvsweb.netbsd.org/bsdweb.cgi/~checkout~/pkgsrc/net/hf6to4/files/
DISTFILES=	hf6to4\?rev=1.3\&content-type=text%2fplain \
		hf6to4.8\?rev=1.2\&content-type=text%2fplain \
		hf6to4.conf\?rev=1.2\&content-type=text%2fplain
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Enables 6to4 IPv6 automatic tunnels

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

NO_BUILD=	yes

BROKEN=		does not fetch.

MAN8=		hf6to4.8

NO_STAGE=	yes
do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}/${i:C/\?.*$//}
.endfor

post-patch:
	${REINPLACE_CMD} -e 's|/usr/pkg|${PREFIX}|g' \
		${WRKSRC}/hf6to4 ${WRKSRC}/hf6to4.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hf6to4 ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/hf6to4.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/hf6to4.conf ${PREFIX}/etc/hf6to4.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
