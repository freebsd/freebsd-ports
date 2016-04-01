# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	superiotool
DISTVERSION=	20121019
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/avg \
		http://www.icyb.net.ua/~avg/distfiles/

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Helper tool for Super I/O chip detection and analysis

LIB_DEPENDS=	libpci.so:devel/libpci

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=The tool is for x86-specific hardware

USES=		gmake tar:bzip2

PLIST_FILES=	sbin/superiotool \
		man/man8/superiotool.8.gz

WRKSRC=		${WRKDIR}/${PORTNAME}
UPSTREAM_VERS=	4.0-2827-g1a00cf0
MAKE_ENV+=	VERSION=-DSUPERIOTOOL_VERSION='\"${UPSTREAM_VERS}\"'

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
