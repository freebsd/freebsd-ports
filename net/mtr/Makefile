PORTNAME=	mtr
PORTVERSION=	0.96
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traceroute and ping in a single network diagnostic tool
WWW=		https://www.bitwizard.nl/mtr/ \
		https://github.com/traviscross/mtr

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf ncurses pkgconfig

GNU_CONFIGURE=	yes
LDFLAGS+=	-lncurses

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11
.if ${FLAVOR} == x11
CONFIGURE_ARGS+=--with-gtk
USE_GNOME=	gtk20
USES+=		gnome
.else
CONFIGURE_ARGS+=--without-gtk
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	traviscross

CONFLICTS_INSTALL=	mtr mtr-nox11

OPTIONS_DEFINE=	IPV6 JSON
OPTIONS_DEFAULT=JSON
JSON_DESC=	JSON support

IPV6_CONFIGURE_ENABLE=	ipv6
JSON_CONFIGURE_WITH=	jansson
JSON_LIB_DEPENDS=	libjansson.so:devel/jansson

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please read about potential security issues"
	@${ECHO_MSG} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
