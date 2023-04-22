PORTNAME=	tlsc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
CATEGORIES=	security

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	TLS connect daemon
WWW=		https://github.com/Zirias/tlsc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c11 gmake ssl

USE_GITHUB=	yes
GH_ACCOUNT=	Zirias
GH_PROJECT=	zimk:zimk
GH_TAGNAME=	0def4fa:zimk

USE_RC_SUBR=	${PORTNAME}

MAKE_ARGS=	V=1
ALL_TARGET=	strip

PLIST_FILES=	bin/tlsc

post-extract:
	@${MV} ${WRKSRC_zimk}/* ${WRKSRC}/zimk/

.include <bsd.port.mk>
