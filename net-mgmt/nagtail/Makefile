# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	nagtail
PORTVERSION=	0.0.31
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.vanheusden.com/nagtail/ \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Tail for the nagios status.dat file

USES=		gmake tar:tgz

PLIST_FILES=	bin/nagtail man/man1/nagtail.1.gz

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nagtail ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nagtail.1.gz ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
