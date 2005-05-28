# New ports collection makefile for:	xbone
# Date created:         		June 8 2000
# Whom:                 		X-Bone Project <xbone@isi.edu>
#
# $FreeBSD$
#

PORTNAME=	XBone-GUI
PORTVERSION=	3.2
CATEGORIES=	net perl5
MASTER_SITES=	http://www.isi.edu/xbone/software/xbone/
DISTNAME=	XBone-${PORTVERSION}

MAINTAINER=	xbone@isi.edu
COMMENT=	The GUI for XBone, a tool to deploy and manage IP-based VPNs

BUILD_DEPENDS=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig \
		${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-INET6 \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/NetAddr/IP.pm:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail\
		${SITE_PERL}/${PERL_ARCH}/Socket6.pm:${PORTSDIR}/net/p5-Socket6\
		${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache2 \
		${SITE_PERL}/${PERL_ARCH}/APR.pm:${PORTSDIR}/www/mod_perl2 \
		${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk \
		${SITE_PERL}/Tk/Getopt.pm:${PORTSDIR}/x11-toolkits/p5-Tk-Getopt \
		${SITE_PERL}/${PERL_ARCH}/Tk/TableMatrix.pm:${PORTSDIR}/x11-toolkits/p5-Tk-TableMatrix

USE_GMAKE=	yes
NO_BUILD=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/XBone-${PORTVERSION}
INSTALL_TARGET=	gui

MAN5=		xbone-gui.conf.5
MAN8=		xb-gui-control.8 xb-apache-config.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 470000
FORBIDDEN=	"X-Bone ${PORTVERSION} does not support FreeBSD prior to 4.7"
.endif

.if ${PERL_LEVEL} < 500601
IGNORE=		X-Bone requires Perl version 5.6.1 or higher. Install lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
