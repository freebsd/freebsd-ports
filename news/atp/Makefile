# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	atp
PORTVERSION=	1.50
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	SUNSITE/system/bbs/mail
DISTFILES=	${DISTNAME}-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QWK message packet reader and composer for FreeBSD

RUN_DEPENDS=	zip:archivers/zip \
		unzip:archivers/unzip

USES=		gmake perl5
USE_PERL5=	run
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message

post-patch:
.for i in atphome bindir mandir
	${REINPLACE_CMD} -e 's,$$($i),$$(DESTDIR)&,g' \
		${WRKSRC}/Makefile.in
.endfor

.include <bsd.port.mk>
