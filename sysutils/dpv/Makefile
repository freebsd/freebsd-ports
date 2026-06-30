PORTNAME=	dpv
DISTVERSION=	0.20260629
CATEGORIES=	sysutils

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Dialog-based progress visualizer

LICENSE=	BSD2CLAUSE

IGNORE_FreeBSD_14=	FreeBSD 14 has dpv in base

LIB_DEPENDS=	libcdialog.so:devel/cdialog \
		libdpv.so:devel/libdpv \
		libfigpar.so:devel/libfigpar

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	dpv

WRKSRC_SUBDIR=	usr.bin/dpv

PLIST_FILES=	bin/dpv share/man/man1/dpv.1.gz

.include <bsd.port.mk>
