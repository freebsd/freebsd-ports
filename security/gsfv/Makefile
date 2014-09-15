# Created by: Frederic Cambus
# $FreeBSD$

PORTNAME=	gsfv
PORTVERSION=	0.2.1
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	LOCAL/ijliao

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create or verify Simple File Verification (SFV) checksum files

LICENSE=	BSD2CLAUSE

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gsfv

post-patch:
	@${REINPLACE_CMD} -e \
		's|\([[:blank:]]\)log|\1bb_log|' ${WRKSRC}/src/backbone.c

.include <bsd.port.mk>
