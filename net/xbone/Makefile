# New ports collection makefile for:    XBone
# Date created:         19 Jan 2001
# Whom:                 Yu-Shun Wang <xbone@isi.edu>
#
# $FreeBSD$
#

PORTNAME=	XBone
PORTVERSION=	2.0
CATEGORIES=     net
MASTER_SITES=   http://www.isi.edu/xbone/software/x-bone/

MAINTAINER=     yushunwa@isi.edu

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 320000
FORBIDDEN=	"X-Bone does not support FreeBSD prior to 3.2"
.endif

USE_GMAKE=	yes
USE_PERL5=      yes
IS_INTERACTIVE=	yes
NO_BUILD=	yes

PERL_LIB=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}

.if !defined(OPTION) || ${OPTION}!=RD && ${OPTION}!=OMGUI
pre-fetch:
	@${ECHO} ""
	@${ECHO} "! You must set variable OPTION=OMGUI or OPTION=RD."
	@${ECHO} "  OMGUI: Install & configure the system for:"
	@${ECHO} "         (1) X-Bone Overlay Manager"
	@${ECHO} "         (2) X-Bone GUI files (html & CGI scripts)"
	@${ECHO} "         (3) X-Bone Overlay DNS server"
	@${ECHO} "  ** NORMALLY, YOU ONLY NEED ONE OMGUI-HOST TO RUN XBONE."
	@${ECHO} ""
	@${ECHO} "  RD: Install the X-Bone Resource Daemon which enables the"
	@${ECHO} "      system to participate in overlays as either a host"
	@${ECHO} "      or a router."
	@${ECHO} "  **  YOU NEED MULTIPLE RD-HOSTS TO CONSTRUCT OVERLAYS."
	@${FALSE}
.elif defined(OPTION)
.if ${OPTION}==RD
BUILD_DEPENDS=  ${PERL_LIB}/Net/Netmask.pm:${PORTSDIR}/net/p5-Net-Netmask \
		${PERL_LIB}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay
INSTALL_TARGET=	rd
PLIST=		${PKGDIR}/pkg-plist.rd
.else
BUILD_DEPENDS=  ${PREFIX}/sbin/httpsd:${PORTSDIR}/www/apache13-ssl\
		${PERL_LIB}/CGI/Carp.pm:${PORTSDIR}/www/p5-CGI \
		${PERL_LIB}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
		${PERL_LIB}/Net/Netmask.pm:${PORTSDIR}/net/p5-Net-Netmask\
		${PERL_LIB}/File/CounterFile.pm:${PORTSDIR}/misc/p5-File-CounterFile \
		${PERL_LIB}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		$[PERL_LIB]/Parse/RecDescent.pm:$[PORTSDIR]/devel/p5-Parse-RecDescent
INSTALL_TARGET= omgui
MAKE_ARGS=	PERL5=${PERL5} SYS=${SYS}
.endif
.endif

MAN1=		xb-pick.1
MAN5=		XB_Defs.pm.5 Xbone_daemon.conf.5 Xbone_daemon.state.5
MAN8=		X-Bone.8 xb-daemon.8 xb-overlay-manager.8 xb-config.8

.include <bsd.port.post.mk>
