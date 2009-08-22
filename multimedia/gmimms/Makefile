# New ports collection makefile for:	gmimms
# Date created:		3 Jul 2007
# Whom:                	Yinghong.Liu <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	gmimms
DISTVERSION=	0.0.9
PORTREVISION=	2
CATEGORIES=	multimedia net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	A frontend to MiMMS (Multimedia Stream ripper)

RUN_DEPENDS=	mimms:${PORTSDIR}/multimedia/mimms

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS+=--disable-nls
INSTALL_TARGET=	install-exec

PLIST_FILES=	bin/gmimms

PORTDOCS=	AUTHORS ChangeLog COPYING INSTALL NEWS README

DESKTOP_ENTRIES=	"GIMMS" \
			"A GTK+ frontend for MiMMS" \
			"" \
			"gmimms" \
			"Application;GTK;AudioVideo;Network;" \
			"false"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
