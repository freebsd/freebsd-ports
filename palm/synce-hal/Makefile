# Created by: Ilya Bakulin <webmaster@kibab.com>
# $FreeBSD$

PORTNAME=	hal
PORTVERSION=	0.14
PORTEPOCH=	1
CATEGORIES=	palm
MASTER_SITES=	SF/synce/SynCE/${PORTVERSION}
PKGNAMEPREFIX=	synce-
DISTNAME=	synce-hal-${PORTVERSION}

MAINTAINER=	webmaster@kibab.com
COMMENT=	SynCE part: manages devices' connections

LIB_DEPENDS=	synce.0:${PORTSDIR}/palm/synce-libsynce  \
		hal.1:${PORTSDIR}/sysutils/hal \
		gnet-2.0.0:${PORTSDIR}/net/gnet2 \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USES=		iconv
USE_PYTHON_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-hal-addon-dir=${PREFIX}/libexec \
			--disable-bluetooth-support

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800074
IGNORE=		requires pppd
.endif

.include <bsd.port.post.mk>
