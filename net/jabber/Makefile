# New ports collection makefile for:	jabber
# Date created:			5 February 2001
# Whom:				joe
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	1.4
CATEGORIES=	net
MASTER_SITES=	http://download.jabber.org/dists/1.4/final/

MAINTAINER=	joe@FreeBSD.org

BUILD_DEPENDS=	pth:${PORTSDIR}/devel/pth \
		libxode-config:${PORTSDIR}/textproc/libxode \
		jabber-config:${PORTSDIR}/net/libjabber

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

rc=${PREFIX}/etc/rc.d

post-install:
	@PREFIX=${PREFIX} ${PERL5} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_SCRIPT} ${FILESDIR}/jabberd.sh ${rc}

.include <bsd.port.mk>
