# New ports collection makefile for:	xrdp
# Date created:				2007-02-19
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	xrdp
PORTVERSION=	0.5.0.20090811cvs
CATEGORIES=	net
MASTER_SITES=	LOCAL/pav

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source Remote Desktop Protocol (RDP) server

USE_AUTOTOOLS=	autoconf:262:env automake:110:env libtool:22
GNU_CONFIGURE=	yes
USE_RC_SUBR=	xrdp

CONFIGURE_ARGS=	--localstatedir=/var

.if defined(WITH_DEBUG)
CFLAGS+=	-DXRDP_DEBUG
.endif

MAN5=		sesman.ini.5 xrdp.ini.5
MAN8=		xrdp-sesman.8 xrdp-sesrun.8 xrdp.8

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e '/chmod/s|startwm.sh|startwm.sh.sample|' ${WRKSRC}/sesman/Makefile.am
	@${REINPLACE_CMD} -e '/chmod/s|rsakeys.ini|rsakeys.ini.sample|' ${WRKSRC}/xrdp/Makefile.am

pre-configure:
	@cd ${WRKSRC} && ./bootstrap
	@${REINPLACE_CMD} -e 's|sesmansysconfdir)/$$$$f|sesmansysconfdir)/$$$$f.sample|' ${WRKSRC}/sesman/Makefile.in
	@${REINPLACE_CMD} -e 's|xrdpsysconfdir)/$$$$f|xrdpsysconfdir)/$$$$f.sample|' ${WRKSRC}/xrdp/Makefile.in

post-install:
	@if [ ! -f ${PREFIX}/etc/xrdp/startwm.sh ]; then \
		${CP} -p ${PREFIX}/etc/xrdp/startwm.sh.sample ${PREFIX}/etc/xrdp/startwm.sh ; \
	fi
	@if [ ! -f ${PREFIX}/etc/xrdp/rsakeys.ini ]; then \
		${CP} -p ${PREFIX}/etc/xrdp/rsakeys.ini.sample ${PREFIX}/etc/xrdp/rsakeys.ini ; \
	fi
	@if [ ! -f ${PREFIX}/etc/xrdp/sesman.ini ]; then \
		${CP} -p ${PREFIX}/etc/xrdp/sesman.ini.sample ${PREFIX}/etc/xrdp/sesman.ini ; \
	fi
	@if [ ! -f ${PREFIX}/etc/xrdp/xrdp.ini ]; then \
		${CP} -p ${PREFIX}/etc/xrdp/xrdp.ini.sample ${PREFIX}/etc/xrdp/xrdp.ini ; \
	fi
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
