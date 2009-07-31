# New ports collection makefile for:	kovpn
# Date created:				13 April 2006
# Whom:					anderson@cnpm.embrapa.br
#
# $FreeBSD$
#

PORTNAME=	kovpn
PORTVERSION=	0.3
PORTREVISION=	5
CATEGORIES=	security kde
MASTER_SITES=	https://projects.fslab.de/projects/kovpn/chrome/site/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pre7

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	A simple GUI for OpenVPN clients

RUN_DEPENDS=	openvpn:${PORTSDIR}/security/openvpn

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_BZIP2=	yes
USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_XORG=	xpm
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262:env automake:19:env libtool:15:env

.include <bsd.port.pre.mk>

pre-configure:
	@cd ${WRKSRC}/admin && ${RM} -f ltmain.sh && ${CP} -f ${LTMAIN} .
	@cd ${WRKSRC} && ${GMAKE} -f admin/Makefile.common

post-install:
	${MKDIR} ${PREFIX}/share/doc/kovpn; \
	${CP} ${FILESDIR}/README ${PREFIX}/share/doc/kovpn

.include <bsd.port.post.mk>
