# New ports collection makefile for:	lcdproc
# Date created:				Sat Jun  1 20:03:41 EDT 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	lcdproc
PORTVERSION=	0.4.5
CATEGORIES=	sysutils
MASTER_SITES=	http://lcdproc.omnipotent.net/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A client/server suite for all kinds of nifty LCD devices

ONLY_FOR_ARCHS=	i386
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-drivers=all

MAN1=		lcdproc.1
MAN8=		LCDd.8

pre-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/LCDd.sh.sample \
		> ${WRKSRC}/LCDd.sh.sample

post-install:
	@${INSTALL_DATA} ${WRKSRC}/LCDd.conf ${PREFIX}/etc/LCDd.conf.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/LCDd.sh.sample ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
