# New ports collection makefile for:	jwhois
# Date created:		15 Jul 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	jwhois
PORTVERSION=	3.2.0
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	jwhois

MAINTAINER=	matusita@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/var/jwhois
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib"

INSTALL_TARGET=	install-strip

MANLANG=	"" sv
MAN1=	jwhois.1

post-install:
	${MKDIR} ${PREFIX}/var/jwhois
	${CHOWN} :nogroup ${PREFIX}/var/jwhois
	${CHMOD} g+w ${PREFIX}/var/jwhois
	${CHOWN} :nogroup ${PREFIX}/bin/jwhois
	${CHMOD} g+s ${PREFIX}/bin/jwhois
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf ${PREFIX}/etc/jwhois.conf.sample
	if [ ! -f ${PREFIX}/etc/jwhois.conf ]; then ${INSTALL_DATA} ${PREFIX}/etc/jwhois.conf.sample ${PREFIX}/etc/jwhois.conf; fi

.include <bsd.port.mk>
