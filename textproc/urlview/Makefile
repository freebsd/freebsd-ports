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
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/contrib/ \
		ftp://ftp.cs.hmc.edu/pub/me/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/mail/mutt/ \
		ftp://ftp.ilog.fr/pub/Mirrors/mutt/contrib/ \
		ftp://ftp.etri.re.kr/pub/mail/mutt/ \
		ftp://ftp.pnm.net/pub/unix/mutt/contrib/

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
