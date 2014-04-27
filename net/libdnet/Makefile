# Created by: Dominic Marks <dominic.marks@btinternet.com>
# $FreeBSD$

PORTNAME=	libdnet
PORTVERSION=	1.12
CATEGORIES?=	net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER?=	onatan@gmail.com
COMMENT=	Simple interface to low level networking routines

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_dnet_bsd_bpf=yes
USES=		libtool:keepla tar:tgz

.if !defined(LIBDNET_SLAVE)
CONFIGURE_ARGS+=	--without-python
USE_LDCONFIG=	yes
.endif

post-patch:
	@${REINPLACE_CMD} 's|shrext|shrext_cmds|g' ${WRKSRC}/configure

.include <bsd.port.mk>
