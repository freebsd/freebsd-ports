# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	debootstrap
PORTVERSION=	1.0.60
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/d/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lifanov@mail.lifanov.com
COMMENT=	Install Debian base system into a directory

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
NO_BUILD=	yes
USES=		gmake tar:xz
MAKE_ARGS=	DESTDIR="${STAGEDIR}"

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Debian GNU/kFreeBSD available only for i386 and amd64

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/debootstrap

post-install:
	@${INSTALL_MAN} ${WRKSRC}/debootstrap.8 \
		${STAGEDIR}${PREFIX}/man/man8/debootstrap.8

.include <bsd.port.mk>
