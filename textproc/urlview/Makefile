# ex:ts=8
# Ports collection makefile for:  urlview
# Date created:			  21 April 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	urlview
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	ftp://ftp.mutt.org/mutt/contrib/ \
		ftp://ftp.sunsite.auc.dk/pub/mail/mutt/contrib/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/mail/mutt/contrib/

#PATCH_SITES=	http://feeding.frenzy.com/~rainking/
#PATCHFILES=	urlview.diff

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	URL extractor/launcher

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
MAN1=		urlview.1

post-patch:
	@${REINPLACE_CMD} -e "s,!!PREFIX!!,${PREFIX},g" ${WRKSRC}/url_handler.sh
	@${REINPLACE_CMD} -e \
		"s,/etc/urlview.conf,${PREFIX}/etc/urlview.conf,g" ${WRKSRC}/*

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/url_handler.sh ${PREFIX}/bin

.include <bsd.port.mk>
