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

USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
MAN1=		urlview.1

post-patch:
	${PERL} -pi.prefix -e 's.!!PREFIX!!.${PREFIX}.g' \
		${WRKSRC}/url_handler.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/url_handler.sh ${PREFIX}/bin

.include <bsd.port.mk>
