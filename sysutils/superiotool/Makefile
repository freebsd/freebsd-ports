PORTNAME=	superiotool
DISTVERSION=	4.18
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://coreboot.org/releases/
DISTFILES=	coreboot-4.18.tar.xz

MAINTAINER=	avg@FreeBSD.org
COMMENT=	Helper tool for Super I/O chip detection and analysis
WWW=		http://www.coreboot.org/Superiotool

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	this tool is for x86-specific hardware

LIB_DEPENDS=	libpci.so:devel/libpci

USES=		gmake tar:bzip2

PLIST_FILES=	sbin/superiotool \
		share/man/man8/superiotool.8.gz

WRKSRC=		${WRKDIR}/coreboot-${DISTVERSION}
WRKSRC_SUBDIR=	util/superiotool
#UPSTREAM_VERS=	4.17-8da4bfe5b
MAKE_ENV+=	VERSION=-DSUPERIOTOOL_VERSION='\"${UPSTREAM_VERS}\"'

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
