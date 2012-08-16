# New ports collection makefile for:	debootstrap
# Date created:		2011-02-26
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	debootstrap
PORTVERSION=	1.0.42
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/d/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Install Debian base system into a directory

RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
NO_BUILD=	yes
USE_GMAKE=	yes
MAKE_ARGS=	DESTDIR="${PREFIX}"

MAN8=		debootstrap.8

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Debian GNU/kFreeBSD available only for i386 and amd64

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,g' \
		${WRKSRC}/debootstrap

post-install:
	@${INSTALL_MAN} ${WRKSRC}/debootstrap.8 \
		${MAN8PREFIX}/man/man8/debootstrap.8
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
