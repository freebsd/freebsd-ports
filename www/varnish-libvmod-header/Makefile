# Created by: anders
# $FreeBSD$

PORTNAME=	libvmod-header
DISTVERSION=	0.3-5
CATEGORIES=	www
MASTER_SITES=	http://anders.fupp.net/distfiles/
PKGNAMEPREFIX=	varnish-
#DISTNAME=	KristianLyng-${PORTNAME}-${VMOD_HEADER_HASH}
#DISTFILES=	KristianLyng-${PORTNAME}-${DISTVERSION}-g${VMOD_HEADER_HASH}.tar.gz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Varnish Module (vmod) for manipulation of duplicated headers

LICENSE=	BSD

BUILD_DEPENDS=	${LOCALBASE}/include/varnish/varnishapi.h:${PORTSDIR}/www/varnish \
		rst2man:${PORTSDIR}/textproc/py-docutils

USE_AUTOTOOLS=	aclocal libtool libtoolize autoheader automake autoconf
USES=		gmake pkgconfig
ACLOCAL_ARGS=	-I m4
LIBTOOLFLAGS=	--copy --force
AUTOMAKE_ARGS=	--add-missing --copy --foreign
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish

MAN3=		vmod_header.3
WRKSRC=		${WRKDIR}/${PORTNAME}-master

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
