# Ports collection makefile for:  vnc2swf
# Date created:			  Sun Dec 7 2:45:15 CET 2003
# Whom:				  Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	vnc2swf
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.unixuser.org/~euske/${PORTNAME}/ \
		ftp://ftp.rewt.org.uk/pub/distfiles/

MAINTAINER=	joe@joeholden.co.uk
COMMENT=	VNC Session Recorder to SWF Flash (Movie) format

USE_XORG=	xmu x11 xi xaw
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/vnc2swf bin/recordwin

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's| -g||g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vnc2swf ${PREFIX}/bin/vnc2swf
	${INSTALL_SCRIPT} ${WRKSRC}/recordwin.sh ${PREFIX}/bin/recordwin

.include <bsd.port.mk>
