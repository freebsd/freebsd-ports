PORTNAME=	mox
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.15
PORTREVISION=	1
CATEGORIES=	mail
PKGNAMESUFFIX=	-mail-server

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern, secure, all-in-one email server
WWW=		https://www.xmox.nl \
		https://github.com/mjl-/mox

LICENSE=	MIT MPL20
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.MIT
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE.MPLv2.0

USES=		go:1.23,modules

GO_MODULE=	github.com/mjl-/mox

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
