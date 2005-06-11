# New ports collection makefile for:	msgconvert
# Date created:				12 Jan 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	msgconvert
PORTVERSION=	20040531
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.webonaut.com/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=	.bz2

MAINTAINER=	klammer@webonaut.com
COMMENT=	Convert .MSG files to multipart MIME messages (mbox)

RUN_DEPENDS=	${SITE_PERL}/OLE/Storage_Lite.pm:${PORTSDIR}/devel/p5-OLE-Storage_Lite \
		${SITE_PERL}/MIME/Words.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_BZIP2=	yes
USE_PERL5=	yes
EXTRACT_AFTER_ARGS=	> ${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}.pl
	${LN} -s ${PREFIX}/bin/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
