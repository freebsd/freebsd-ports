# New ports collection makefile for:   6to4
# Date created:                3 July 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	6to4
PORTVERSION=	1.3
CATEGORIES=	net ipv6
MASTER_SITES=	http://cvsweb.netbsd.org/bsdweb.cgi/~checkout~/pkgsrc/net/6to4/files/
DISTFILES=	6to4\?rev=1.9\&content-type=text%2fplain \
		6to4.8\?rev=1.6\&content-type=text%2fplain \
		6to4.conf\?rev=1.3\&content-type=text%2fplain
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	fuyuki@hadaly.org

USE_REINPLACE=	yes
USE_PERL5=	yes
NO_BUILD=	yes

MAN8=		6to4.8

do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}/${i:C/\?.*$//}
.endfor

do-patch:
	${REINPLACE_CMD} -e 's|\@LOCALBASE\@/bin/perl|${PERL}|; \
		s|\@PREFIX\@|${PREFIX}|' ${WRKSRC}/6to4
	${REINPLACE_CMD} -e 's|/usr/pkg|${PREFIX}|; \
		s|ip6mode=autohost|ipv6_gateway_enable="NO"|' ${WRKSRC}/6to4.8
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/6to4 ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/6to4.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/6to4.conf ${PREFIX}/etc/6to4.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
