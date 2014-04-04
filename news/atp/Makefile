# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=		atp
PORTVERSION=		1.50
PORTREVISION=	1
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/bbs/mail
DISTFILES=		${DISTNAME}-src.tar.gz

MAINTAINER=		ports@FreeBSD.org
COMMENT=	A QWK message packet reader and composer for FreeBSD

RUN_DEPENDS=		zip:${PORTSDIR}/archivers/zip \
			unzip:${PORTSDIR}/archivers/unzip

USES=	gmake
GNU_CONFIGURE=		YES
SUB_FILES=	pkg-message

post-patch:
.for i in atphome bindir mandir
	${REINPLACE_CMD} -e 's,$$($i),$$(DESTDIR)&,g' \
		${WRKSRC}/Makefile.in
.endfor

.include <bsd.port.mk>
