# New ports collection makefile for:	mldonkey link submitter
# Date created:				Fri Feb 21 14:11:00 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	0.0.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://ircnet.de/home/cru/ed2k_urlslave/dist/
PKGNAMESUFFIX=	-urlslave
DISTNAME=	mlurlslave-v${PORTVERSION:S/^0.0.//}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	GTK+ enabled Perl script for adding ed2k:// links to MLDonkey

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk

USE_PERL5=	yes
USE_SIZE=	yes
NO_BUILD=	yes

BINARY_NAME=	mlurlslave

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
