# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=		hitch
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=		1.0.0-beta1
CATEGORIES=		security

MAINTAINER=		zi@FreeBSD.org
COMMENT=		TLS proxy to forward connections to an unencrypted backend

LICENSE=		BSD2CLAUSE

LIB_DEPENDS=		libev.so:${PORTSDIR}/devel/libev

USERS=			nobody
GROUPS=			nobody

USES=			autoreconf
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--localstatedir=/var/run
USE_OPENSSL=		yes
USE_RC_SUBR=		${PORTNAME}
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
USE_GITHUB=		yes
GH_ACCOUNT=		varnish

post-patch:
	${REINPLACE_CMD} 's|stud|${PORTNAME}|g' ${WRKSRC}/*.* ${WRKSRC}/src/*

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
