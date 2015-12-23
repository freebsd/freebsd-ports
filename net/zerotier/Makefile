# Created by: Corey Smith <corsmith@gmail.com>
# $FreeBSD$

PORTNAME=	zerotier
DISTVERSION=	1.1.0
CATEGORIES=	net
MASTER_SITES=	GH

MAINTAINER=	corsmith@gmail.com
COMMENT=	Network virtualization everywhere

LICENSE=	GPLv3

USES=		gmake
USE_RC_SUBR=	zerotier

USE_GITHUB=	yes
GH_ACCOUNT=	zerotier
GH_PROJECT=	ZeroTierOne
GH_TAGNAME=	5db538d
CFLAGS+=	-flax-vector-conversions

PLIST_FILES=	bin/zerotier-cli bin/zerotier-idtool sbin/zerotier-one

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zerotier-one ${STAGEDIR}${PREFIX}/sbin/
.for l in zerotier-cli zerotier-idtool
	${LN} -sf ../sbin/zerotier-one ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

.include <bsd.port.mk>
