# New ports collection makefile for:	poptop
# Date created:		04 October 1999
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	poptop
PORTVERSION=	1.1.4.b4
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	pptpd-${PORTVERSION:S/.b/-b/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Windows 9x compatible PPTP (VPN) server

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}" \

MAN5=		pptpd.conf.5
MAN8=		pptpd.8 pptpctrl.8

.if !defined(WITH_KERNPPP)
CONFIGURE_ARGS+=	--with-bsdppp
.endif

post-patch:
.for file in bcrelay.c pptpd.c
	@${REINPLACE_CMD} -e 's|"out_getopt\.h"|<getopt.h>|g' ${WRKSRC}/${file}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/pptpd.conf \
		${PREFIX}/etc/pptpd.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pptpd.sh \
		${PREFIX}/etc/rc.d/pptpd.sh.sample

.include <bsd.port.mk>
