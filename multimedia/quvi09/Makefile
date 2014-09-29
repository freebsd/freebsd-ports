# Created by: Toni Gundogdu <legatvs@gmail.com>
# $FreeBSD$

PORTNAME=	quvi
PORTVERSION=	0.9.5
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line tool for parsing flash media stream URLs

LICENSE=	AGPLv3

BUILD_DEPENDS=	libquvi09>=0.9:${PORTSDIR}/multimedia/libquvi09
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=09

PLIST_FILES=	bin/quvi09 \
		man/man1/quvi-dump09.1.gz \
		man/man1/quvi-get09.1.gz \
		man/man1/quvi-info09.1.gz \
		man/man1/quvi-scan09.1.gz \
		man/man1/quvi09.1.gz \
		man/man5/quvirc09.5.gz

.include <bsd.port.mk>
