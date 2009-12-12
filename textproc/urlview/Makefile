# ex:ts=8
# Ports collection makefile for:  urlview
# Date created:			  21 April 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	urlview
PORTVERSION=	0.9
PORTREVISION=	3
CATEGORIES=	textproc www
MASTER_SITES=	ftp://ftp.mutt.org/mutt/contrib/ \
		ftp://ftp.sunsite.auc.dk/pub/mail/mutt/contrib/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/mail/mutt/contrib/

#PATCH_SITES=	http://feeding.frenzy.com/~rainking/
#PATCHFILES=	urlview.diff

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	URL extractor/launcher

BROKEN=		fails to package

GNU_CONFIGURE=	yes
MAN1=		urlview.1
SUB_FILES=	gecko.sh
SUB_LIST=	GECKO=${GECKO}

.include <bsd.port.pre.mk>

.if defined(WITH_GECKO)
USE_GECKO=	firefox firefox-devel seamonkey mozilla
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.else
GECKO=		firefox
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,!!PREFIX!!,${PREFIX},g" \
		-e "s,/usr/X11R6,${X11BASE},g" ${WRKSRC}/url_handler.sh
	@${REINPLACE_CMD} -e \
		"s,/etc/urlview.conf,${PREFIX}/etc/urlview.conf,g" ${WRKSRC}/*

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/url_handler.sh ${PREFIX}/bin

.include <bsd.port.post.mk>
