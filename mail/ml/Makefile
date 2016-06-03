# Created by: Jeroen Hogeveen <albast@xs4all.nl>
# $FreeBSD$

PORTNAME=	ml
PORTVERSION=	3.4
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 IMAP client

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USES=		imake motif
USE_XORG=	ice sm x11 xext xmu xp xt

post-patch:
	@${REINPLACE_CMD} 's,ML_LIBDIR),DESTDIR)$$(&,g' \
		${WRKSRC}/Imakefile

pre-configure:
	@${ECHO_MSG} "===>  Building c-client"
	@( cd ${WRKSRC}/../imap-4; make bsi )
	@( cd ${WRKSRC}; ${RM} -f makeproto )

.include <bsd.port.mk>
