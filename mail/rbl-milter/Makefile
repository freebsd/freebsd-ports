# Created by: wolpert
# $FreeBSD$

PORTNAME=	rbl-milter
PORTVERSION=	0.30
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://www.gnu-darwin.org/distfiles/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Milter that adds mail header warnings on mail from open-relays

USES=		gmake
GNU_CONFIGURE=	yes

USE_RC_SUBR=	rblmilter
PLIST_FILES=	sbin/rbl-milter

CONFIGURE_ARGS+=	--with-sendmail=${MILTERBASE} \
			--with-sendmail-obj=${MILTERBASE}/lib

.include "${.CURDIR}/../sendmail/bsd.milter.mk"

.include <bsd.port.mk>
