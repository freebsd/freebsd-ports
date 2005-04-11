# New ports collection makefile for:	jabber
# Date created:			5 February 2001
# Whom:				joe
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	1.4.3.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://devel.amessage.info/jabberd14/
DISTNAME=	${PORTNAME}d-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Online presence and instant messaging server

LIB_DEPENDS=	pth.20:${PORTSDIR}/devel/pth \
		expat.5:${PORTSDIR}/textproc/expat2

USE_RC_SUBR=	jabberd.sh
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS+=	--enable-ssl
.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

#JABDIR=		${PORTNAME}-${PORTVERSION}
# Save this data for use later: jabber doesn't have an install target
# or a sane set of defaults.
post-patch:
	${ECHO} "${WRKSRC}" > ${WRKSRC}/.wrksrc-freebsd
	${ECHO} "${PREFIX}" > ${WRKSRC}/.prefix-freebsd
	${ECHO} "${INSTALL_DATA}" > ${WRKSRC}/.install_data-freebsd
	${ECHO} "${INSTALL_SCRIPT}" > ${WRKSRC}/.install_script-freebsd
	${ECHO} "${INSTALL_PROGRAM}" > ${WRKSRC}/.install_program-freebsd

post-configure:
	${REINPLACE_CMD} -e "s#-I\. -I\.\. #-I\. -I\.\. -I${LOCALBASE}/include #" -e "s#-L/usr/lib#-L/usr/lib -L${LOCALBASE}/lib#" ${WRKSRC}/platform-settings

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${INSTALL_SCRIPT} ${WRKDIR}/jabberd.sh ${PREFIX}/etc/rc.d/

.include <bsd.port.mk>
