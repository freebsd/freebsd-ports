# New ports collection makefile for:	radvd
# Date created:				Fri Jul  6 03:17:33 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	radvd
PORTVERSION=	0.7.1
CATEGORIES=	net ipv6
MASTER_SITES=	http://v6web.litech.org/radvd/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p4/pl4/}

MAINTAINER=	pat@FreeBSD.org

GNU_CONFIGURE=	yes

MAN5=	radvd.conf.5
MAN8=	radvd.8 radvdump.8

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/INTRO.html ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/radvd.conf.example ${PREFIX}/etc
.endif #NOPORTDOCS
	@${SED} -e "s|/usr/local|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.mk>
