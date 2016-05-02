# Created by: Sean Greven <sean.greven@gmail.com>
# $FreeBSD$

PORTNAME=	fwknop
PORTVERSION=	2.6.8
CATEGORIES=	security
MASTER_SITES=	http://www.cipherdyne.org/fwknop/download/

MAINTAINER=	sean.greven@gmail.com
COMMENT=	SPA implementation for Linux and FreeBSD

LICENSE=	GPLv2

CPE_VENDOR=	cipherdyne

OPTIONS_DEFINE=	GPGME

OPTIONS_SINGLE=	FW
OPTIONS_SINGLE_FW=	IPFW PF

OPTIONS_DEFAULT=	GPGME IPFW

FW_DESC=	Firewall Backend
IPFW_DESC=	Use the IPFW firewall
PF_DESC=	Use the PF firewall.
GPGME_DESC=	Build support for gpgme

USES=		cpe libtool
USE_LDCONFIG=	yes
USE_RC_SUBR=	fwknopd

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
INFO=		libfko

IPFW_CONFIGURE_WITH=	ipfw=/sbin/ipfw

PF_CONFIGURE_WITH=	pf=/sbin/pfctl

GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPGME_CONFIGURE_WITH=	gpgme

post-stage:
	(cd ${STAGEDIR}${PREFIX}/etc/fwknop && ${MV} access.conf access.conf.sample)
	(cd ${STAGEDIR}${PREFIX}/etc/fwknop && ${MV} fwknopd.conf fwknopd.conf.sample)

.include <bsd.port.mk>
