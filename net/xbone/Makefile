# New ports collection makefile for:    XBone
# Date created:         19 Jan 2001
# Whom:                 Yu-Shun Wang <xbone@isi.edu>
#
# $FreeBSD$
#

PORTNAME=	XBone
PORTVERSION=	3.2
CATEGORIES=	net perl5
MASTER_SITES=	http://www.isi.edu/xbone/software/xbone/

MAINTAINER=	xbone@isi.edu
COMMENT=	Deploys and manages IP-based VPNs (aka "virtual Internets")

BUILD_DEPENDS=	${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/${PERL_ARCH}/IO/Socket/Multicast.pm:${PORTSDIR}/net/p5-IO-Socket-Multicast \
		${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-INET6 \
		${SITE_PERL}/Parallel/ForkManager.pm:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/Graph.pm:${PORTSDIR}/math/p5-Graph \
		${SITE_PERL}/NetAddr/IP.pm:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
		${SITE_PERL}/${PERL_ARCH}/Socket6.pm:${PORTSDIR}/net/p5-Socket6 \
		${SITE_PERL}/Net/SSH/Perl.pm:${PORTSDIR}/net/p5-Net-SSH-Perl \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk \
		${SITE_PERL}/Tk/Getopt.pm:${PORTSDIR}/x11-toolkits/p5-Tk-Getopt \
		${SITE_PERL}/${PERL_ARCH}/Tk/TableMatrix.pm:${PORTSDIR}/x11-toolkits/p5-Tk-TableMatrix

USE_GMAKE=	yes
#IS_INTERACTIVE=	yes
NO_BUILD=	yes
USE_PERL5=	yes
USE_OPENLDAP=	yes

INSTALL_TARGET=	node

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 470000
FORBIDDEN=	"X-Bone ${PORTVERSION} does not support FreeBSD prior to 4.7"
.endif

.if ${PERL_LEVEL} < 500601
IGNORE=		X-Bone requires Perl version 5.6.1 or higher. Install lang/perl5.8 and try again.
.endif

MAN5=		XB_Params.pm.5 xbone.conf.5
MAN8=		X-Bone.8 xb-node-daemon.8 xb-node-control.8 xbonectl.8 xb-ldap-config.8

.include <bsd.port.post.mk>
