# Created by: ccowart@timesinks.net
# $FreeBSD$

PORTNAME=	confman
PORTVERSION=	1.9.4b
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.timesinks.net/distfiles/

MAINTAINER=	ccowart@timesinks.net
COMMENT=	Revision controlled configuration manager

BROKEN=		unfetchable

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	bash:shells/bash \
		svn:devel/subversion \
		sudo:security/sudo \
		greadlink:sysutils/coreutils \
		wget:ftp/wget

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--localstatedir=/var

.include <bsd.port.mk>
