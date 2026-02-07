PORTNAME=	yconalyzer
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP Traffic Analyzer
WWW=		https://yconalyzer.sourceforge.net/

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake tar:bzip2

PLIST_FILES=	bin/yconalyzer \
		share/man/man8/yconalyzer.8.gz

pre-install:
	${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.mk>
