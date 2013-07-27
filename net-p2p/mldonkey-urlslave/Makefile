# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mldonkey
PORTVERSION=	0.0.1
PORTREVISION=	4
CATEGORIES=	net-p2p perl5
MASTER_SITES=	http://home.ircnet.de/cru/ed2k_urlslave/dist/
PKGNAMESUFFIX=	-urlslave
DISTNAME=	mlurlslave-v${PORTVERSION:S/^0.0.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ enabled Perl script for adding ed2k:// links to MLDonkey

BUILD_DEPENDS=	p5-Gtk>=0:${PORTSDIR}/x11-toolkits/p5-Gtk

USE_PERL5=	yes
NO_BUILD=	yes
USES=		shebangfix
SHEBANG_FILES=	${BINARY_NAME}

BINARY_NAME=	mlurlslave

post-extract:
	@${GREP} '^#' ${WRKSRC}/${BINARY_NAME} | ${GREP} -v '/usr/bin/perl' > ${WRKDIR}/README

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
