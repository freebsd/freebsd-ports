# $FreeBSD$

PORTNAME=	kbfsd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
CATEGORIES=	security

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Service daemon for the Keybase filesystem (KBFS)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	keybase>=3.0.0_1:security/keybase \
		jq:textproc/jq

USE_GITHUB=	yes
GH_ACCOUNT=	0mp

NO_ARCH=	yes

PLIST_FILES=	etc/rc.d/kbfsd \
		man/man5/kbfsd.5.gz

.include <bsd.port.mk>
