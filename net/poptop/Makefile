# New ports collection makefile for:	poptop
# Date created:		04 October 1999
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	poptop
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	pptpd-${PORTVERSION:S/.b/-b/}

MAINTAINER=	nivo+kw+ports.bfa274@is-root.com
COMMENT=	Windows 9x compatible PPTP (VPN) server

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

USE_RC_SUBR=	pptpd.sh

MAN5=		pptpd.conf.5
MAN8=		pptpd.8 pptpctrl.8

.if !defined(WITH_KERNPPP)
CONFIGURE_ARGS+=	--with-bsdppp
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/pptpctrl.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/pptpd.8
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/pptpd.conf.5

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/pptpd.conf \
		${PREFIX}/etc/pptpd.conf.sample

.include <bsd.port.mk>
