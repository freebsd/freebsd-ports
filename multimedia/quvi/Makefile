# Created by: Toni Gundogdu <legatvs@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/quvi/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	quvi
PORTVERSION=	0.9.5
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}/${PORTNAME}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line tool for parsing flash media stream URLs

LICENSE=	AGPLv3

BUILD_DEPENDS=	libquvi>=0.4.0:${PORTSDIR}/multimedia/libquvi
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	limit:0.4.[0-9]*

USES=		pkgconfig tar:xz
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/quvi \
		man/man1/quvi-dump.1.gz \
		man/man1/quvi-get.1.gz \
		man/man1/quvi-info.1.gz \
		man/man1/quvi-scan.1.gz \
		man/man1/quvi.1.gz \
		man/man5/quvirc.5.gz

.include <bsd.port.mk>
