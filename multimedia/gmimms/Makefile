# Created by: Yinghong.Liu <liu_yinghong@yahoo.com.cn>
# $FreeBSD$

PORTNAME=	gmimms
DISTVERSION=	0.0.9
PORTREVISION=	8
CATEGORIES=	multimedia net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend to MiMMS (Multimedia Stream ripper)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses EOL Python 2.7 via multimedia/mimms
EXPIRATION_DATE=2021-06-23

RUN_DEPENDS=	mimms:multimedia/mimms

USES=		gnome pkgconfig tar:bzip2
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
INSTALL_TARGET=	install-exec

CFLAGS+=	-Wno-error=return-type

PORTDOCS=	AUTHORS ChangeLog
PLIST_FILES=	bin/gmimms

DESKTOP_ENTRIES="GMiMMS" \
		"Multimedia Stream ripper" \
		"" \
		"gmimms" \
		"GTK;AudioVideo;Network;" \
		"false"

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
