# ex:ts=8
# Ports collection makefile for:    dhcp
# Date created:         7 Mar 1996
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	isc-dhcp3
PORTVERSION=	3.0.b1.14
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.isc.org/isc/dhcp/
DISTNAME=	dhcp-3.0b1pl14

MAINTAINER=	obrien@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/bind/res_update.h:${PORTSDIR}/net/bind8

Y2K=		http://www.isc.org/y2k.html

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-nsupdate

MAN5=		dhclient.conf.5 dhclient.leases.5 dhcp-contrib.5 \
		dhcp-eval.5 dhcp-options.5 dhcpd.conf.5 \
		dhcpd.leases.5
MAN8=		dhclient.8 dhclient-script.8 dhcpd.8 dhcrelay.8

post-patch:
	@${PERL} -pi.fbsd -e 's.!!PREFIX!!.${PREFIX}.g' ${WRKSRC}/includes/dhcpd.h
	@${PERL} -pi.fbsd -e 's.!!PREFIX!!.${PREFIX}.g' ${WRKSRC}/client/scripts/freebsd

post-install:
	${TOUCH} /var/db/dhcpd.leases
.for file in dhclient dhcpd dhcrelay
	if [ -f ${PREFIX}/sbin/${file} ]; then \
		strip ${PREFIX}/sbin/${file}; \
	fi
.endfor

.include <bsd.port.mk>
