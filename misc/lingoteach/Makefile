# New ports collection makefile for:   lingoteach
# Date created:        01 September 2002
# Whom:                Marcus vA
#
# $FreeBSD$
#

PORTNAME=      lingoteach
PORTVERSION=   0.3.7
CATEGORIES=    misc
MASTER_SITES=  http://unc.dl.sourceforge.net/sourceforge/lingoteach/

MAINTAINER=    mva121@gmx.net

BUILD_DEPENDS= gtk-query-immodules-2.0:${PORTSDIR}/x11-toolkits/gtk20:install \
	       xml2-config:${PORTSDIR}/textproc/libxml2:install
LIB_DEPENDS=   xml2.5:${PORTSDIR}/textproc/libxml2:install \
	       gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20:install

GNU_CONFIGURE= yes
CONFIGURE_TARGET=
USE_GMAKE=     yes

post-install::
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} " If you want the sound snippets too, go to the projects "
	@${ECHO_MSG} " homepage - http://lingoteach.org, fetch the tar ball   "
	@${ECHO_MSG} " of the sound snippets and copy the content of data     "
	@${ECHO_MSG} " to $PREFIX/share/lingoteach/data.                      "
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>
