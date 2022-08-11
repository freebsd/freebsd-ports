PORTNAME=	yconalyzer
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP Traffic Analyzer

GNU_CONFIGURE=	yes
USES=		gmake tar:bzip2

PLIST_FILES=	bin/yconalyzer \
		man/man8/yconalyzer.8.gz

pre-install:
	${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.mk>
