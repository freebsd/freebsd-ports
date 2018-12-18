# Created by: Sebastian Yepes F. <esn@x123.info>
# $FreeBSD$

PORTNAME=	apachetop
PORTVERSION=	0.18.4
CATEGORIES=	sysutils

MAINTAINER=	lukasz@wasikowski.net
COMMENT=	Apache realtime log stats

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf ncurses readline
USE_GITHUB=	yes
GH_ACCOUNT=	tessus

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	ADNS FAM PCRE

ADNS_DESC=	Asynchronous-capable DNS support
ADNS_LIB_DEPENDS=	libadns.so:dns/adns
ADNS_CONFIGURE_WITH=	adns=${LOCALBASE}

FAM_LIB_DEPENDS=	libfam.so:devel/fam
FAM_CONFIGURE_WITH=	fam=${LOCALBASE}

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre=${LOCALBASE}

.include <bsd.port.mk>
