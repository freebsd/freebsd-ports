# New ports collection makefile for:	jwhois
# Date created:		15 Jul 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	jwhois
PORTVERSION=	2.4.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	jwhois

MAINTAINER=	matusita@jp.FreeBSD.org

LIB_DEPENDS=    intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --localstatedir=${PREFIX}/var/jwhois
USE_GMAKE=	yes
CONFIGURE_ENV=  CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib"

INSTALL_TARGET=	install-strip

MAN1=	jwhois.1

post-install:
	${MKDIR} ${PREFIX}/var/jwhois
	${CHOWN} :nogroup ${PREFIX}/var/jwhois
	${CHMOD} g+w ${PREFIX}/var/jwhois
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf ${PREFIX}/etc

.include <bsd.port.mk>
