# New ports collection makefile for:	jabber
# Date created:			5 February 2001
# Whom:				joe
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.jabber.org/dists/1.4/final/

MAINTAINER=	joe@FreeBSD.org

BUILD_DEPENDS=	pth-config:${PORTSDIR}/devel/pth

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

rc=${PREFIX}/etc/rc.d

post-install:
	@PREFIX=${PREFIX} ${PERL5} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_SCRIPT} ${FILESDIR}/jabberd.sh ${rc}

.include <bsd.port.mk>
