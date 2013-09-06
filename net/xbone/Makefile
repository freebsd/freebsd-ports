# New ports collection makefile for:    XBone
# Date created:         19 Jan 2001
# Whom:                 Yu-Shun Wang <xbone@isi.edu>
#
# $FreeBSD$
#

PORTNAME=	XBone
PORTVERSION=	3.2
PORTREVISION=	6
CATEGORIES=	net perl5
MASTER_SITES=	http://www.isi.edu/xbone/software/xbone/

MAINTAINER=	xbone@isi.edu
COMMENT=	Deploys and manages IP-based VPNs (aka "virtual Internets")

BUILD_DEPENDS=	p5-AppConfig>=0:${PORTSDIR}/devel/p5-AppConfig \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-IO-Socket-Multicast>=0:${PORTSDIR}/net/p5-IO-Socket-Multicast \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		p5-IO-Socket-Multicast>=0.25:${PORTSDIR}/net/p5-IO-Socket-Multicast \
		p5-IO-Socket-Multicast6>=0:${PORTSDIR}/net/p5-IO-Socket-Multicast6 \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Graph>=0:${PORTSDIR}/math/p5-Graph \
		p5-NetAddr-IP>0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-Net-Netmask>=0:${PORTSDIR}/net-mgmt/p5-Net-Netmask \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Mail-Sendmail>=0:${PORTSDIR}/mail/p5-Mail-Sendmail \
		p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6 \
		p5-Net-SSH-Perl>=0:${PORTSDIR}/net/p5-Net-SSH-Perl \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk \
		p5-Tk-Getopt>=0:${PORTSDIR}/x11-toolkits/p5-Tk-Getopt \
		p5-Tk-TableMatrix>=0:${PORTSDIR}/x11-toolkits/p5-Tk-TableMatrix

USE_GMAKE=	yes
#IS_INTERACTIVE=	yes
NO_BUILD=	yes
USES=		perl5
USE_OPENLDAP=	yes

INSTALL_TARGET=	node

MAN5=		XB_Params.pm.5 xbone.conf.5
MAN8=		X-Bone.8 xb-node-daemon.8 xb-node-control.8 xbonectl.8 xb-ldap-config.8

post-patch:
	${RM} -rf ${WRKSRC}/ports/*

.include <bsd.port.mk>
