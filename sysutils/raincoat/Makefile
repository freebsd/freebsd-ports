# New ports collection makefile for:	raincoat
# Date created:				24 July 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=		raincoat
PORTVERSION=		0.10
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xbox-linux
EXTRACT_SUFX=		.tbz2

MAINTAINER=		ed@fxq.nl
COMMENT=		BIOS flash utility for the Microsoft Xbox

# Xbox is i386
ONLY_FOR_ARCHS=		i386

USE_REINPLACE=		yes
USE_BZIP2=		yes

PLIST_FILES=		sbin/raincoat \
			etc/raincoat.conf

pre-configure:
	@${REINPLACE_CMD} -e 's|\/etc\/raincoat\.conf|${PREFIX}&|g' \
		${WRKSRC}/src/raincoat.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/raincoat ${PREFIX}/sbin/raincoat
	${INSTALL_DATA} ${WRKSRC}/etc/raincoat.conf ${PREFIX}/etc/raincoat.conf

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Doesn't build on < 5.x"
.endif

.include <bsd.port.post.mk>
