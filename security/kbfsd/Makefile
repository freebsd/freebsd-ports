# $FreeBSD$

PORTNAME=	kbfsd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Service daemon for the Keybase filesystem (KBFS)

# There is no license file in v1.2.0.
LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	keybase>=3.0.0_1:security/keybase

USE_GITHUB=	yes
GH_ACCOUNT=	0mp

NO_ARCH=	yes

PLIST_FILES=	etc/rc.d/kbfsd \
		man/man5/kbfsd.5.gz

.include <bsd.port.mk>
