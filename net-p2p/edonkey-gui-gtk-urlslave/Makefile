# New ports collection makefile for:	edonkey gtk gui link submitter
# Date created:				Sat Feb 23 13:13:08 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.0.2
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://home.ircnet.de/cru/ed2k_urlslave/dist/
PKGNAMESUFFIX=	-gui-gtk-urlslave
DISTNAME=	ed2k_urlslave-v2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ enabled Perl script for adding ed2k:// links to ed2k GTK+ GUI

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
RUN_DEPENDS=	ed2k_gui:${PORTSDIR}/net/edonkey-gui-gtk

USE_PERL5=	yes
NO_BUILD=	yes

BINARY_NAME=	ed2k_urlslave

post-extract:
	@${GREP} '^#' ${WRKSRC}/${BINARY_NAME} | ${GREP} -v '/usr/bin/perl' > ${WRKDIR}/README

post-patch:
	@${PERL} -pi -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/${BINARY_NAME}

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
	@${CHMOD} 0755 ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
	@${INSTALL_DATA} ${WRKDIR}/README ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/${BINARY_NAME} ${PREFIX}/bin

post-install:
	@${SED} -e 's|/usr/local/|${PREFIX}/|' ${PKGMESSAGE}

.include <bsd.port.mk>
