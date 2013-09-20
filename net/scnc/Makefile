# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	scnc
PORTVERSION=	1.05
CATEGORIES=	net security
MASTER_SITES=	http://gomor.org/files/

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	SSL Capable Netcat

LICENSE=	BSD

RUN_DEPENDS=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6
BUILD_DEPENDS:=	${RUN_DEPENDS}

PLIST_FILES=	bin/${PORTNAME}
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
