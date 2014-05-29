# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pmt
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://hansmi.ch/download/pmt/ \
		LOCAL/glarkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small collection of filters which can be added to UNIX pipes

USES=		gmake tar:bzip2

PLIST_FILES=	bin/pmt

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800071
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config.mak
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pmt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
