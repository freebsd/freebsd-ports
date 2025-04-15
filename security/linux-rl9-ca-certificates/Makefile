PORTNAME=	ca-certificates
PORTVERSION=	2024.2.69
DISTVERSIONSUFFIX=	_v8.0.303-91.4.el9_4
PORTREVISION=	1
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mozilla CA root certificate bundle (Rocky Linux ${LINUX_DIST_VER})

LICENSE=	PD

USES=		linux:rl9
USE_LINUX=	p11-kit
USE_LINUX_RPM=	noarch

OPTIONS_DEFINE=	DOCS

post-stage:
	${LINUXBASE}/bin/sh ${STAGEDIR}${PREFIX}/usr/bin/update-ca-trust \
		extract -o ${STAGEDIR}${PREFIX}/etc/pki/ca-trust/extracted

.include <bsd.port.mk>
