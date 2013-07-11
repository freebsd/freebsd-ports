# Created by: anderson@cnpm.embrapa.br
# $FreeBSD$

PORTNAME=	kovpn
PORTVERSION=	0.3
PORTREVISION=	10
CATEGORIES=	security kde
MASTER_SITES=	https://projects.fslab.de/projects/kovpn/chrome/site/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pre7

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GUI for OpenVPN clients

RUN_DEPENDS=	openvpn:${PORTSDIR}/security/openvpn

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_BZIP2=	yes
USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
USES=		gettext gmake
INSTALLS_ICONS=	yes
USE_XORG=	xpm
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:env automake:env libtool

AUTOTOOLSFILES=	admin/cvs.sh

.include <bsd.port.pre.mk>

pre-configure:
	@cd ${WRKSRC}/admin && ${RM} -f ltmain.sh && ${CP} -f ${LTMAIN} .
	@cd ${WRKSRC} && ${GMAKE} -f admin/Makefile.common

post-install:
	${MKDIR} ${PREFIX}/share/doc/kovpn; \
	${CP} ${FILESDIR}/README ${PREFIX}/share/doc/kovpn

.include <bsd.port.post.mk>
