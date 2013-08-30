# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	libvmod-statsd
PORTVERSION=	0.02
CATEGORIES=	www

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Varnish Module (vmod) for sending statistics to Statsd

LICENSE=	BSD

BUILD_DEPENDS=	${LOCALBASE}/include/varnish/varnishapi.h:${PORTSDIR}/www/varnish \
	${LOCALBASE}/share/libvmod-header/vmod_header.vcc:${PORTSDIR}/www/varnish-libvmod-header \
	rst2man:${PORTSDIR}/textproc/py-docutils

USE_GITHUB=	yes
GH_ACCOUNT=	jib
GH_COMMIT=	6283ad1
GH_TAGNAME=	0.02

USE_PYTHON=	yes
USE_AUTOTOOLS=	aclocal libtool libtoolize autoheader:env automake autoconf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
LIBTOOLFLAGS=	--copy --force
AUTOMAKE_ARGS=	--add-missing --copy --foreign
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE} VARNISHSRC=${LOCALBASE}/include/varnish
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish

MAN3=	vmod_statsd.3

# TODO do not override run-autotools target
run-autotools:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ./autogen.sh

.include <bsd.port.mk>
