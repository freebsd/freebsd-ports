# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	nagtail
PORTVERSION=	0.0.31
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.vanheusden.com/nagtail/ \
		http://mirrors.rit.edu/zi/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Tail for the nagios status.dat file

USE_GMAKE=	yes

MAN1=		nagtail.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/nagtail

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/nagtail ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/nagtail.1.gz ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
