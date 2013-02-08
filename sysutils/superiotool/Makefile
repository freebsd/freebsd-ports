# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	superiotool
DISTVERSION=	20121019
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.icyb.net.ua/~avg/distfiles/
MASTER_SITE_SUBDIR=avg

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Helper tool for Super I/O chip detection and analysis

LIB_DEPENDS=	pci:${PORTSDIR}/devel/libpci

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=The tool is for x86-specific hardware

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	sbin/superiotool
MAN8=		superiotool.8

WRKSRC=		${WRKDIR}/${PORTNAME}
UPSTREAM_VERS=	4.0-2827-g1a00cf0
MAKE_ENV+=	VERSION=-DSUPERIOTOOL_VERSION='\"${UPSTREAM_VERS}\"'

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
