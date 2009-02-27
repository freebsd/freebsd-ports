# New ports collection makefile for:	xrdp
# Date created:				2007-02-19
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	xrdp
PORTVERSION=	0.4.1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source Remote Desktop Protocol (RDP) server

USE_RC_SUBR=	xrdp

.if defined(WITH_DEBUG)
CFLAGS+=	-DXRDP_DEBUG
.endif

MAN5=		sesman.ini.5 xrdp.ini.5
MAN8=		sesman.8 sesrun.8 xrdp.8

SUB_FILES=	pkg-message

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile | \
		${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/local/xrdp|${PREFIX}/lib/${PORTNAME}|; \
		 s|/etc/xrdp|${PREFIX}/etc/${PORTNAME}|; \
		 s|/usr/local/man|${MANPREFIX}/man|; \
		 s|/usr/doc/xrdp|${DOCSDIR}|; \
		 s|CFLAGS =|CFLAGS +=|; s|gcc|${CC}|; s|-ldl||'
	@${REINPLACE_CMD} -e \
		's|startwm\.sh|${PREFIX}/lib/${PORTNAME}/&|; \
		 s|\./sesman\.log|/var/log/sesman.log|' \
		 ${WRKSRC}/sesman/sesman.ini
	@${REINPLACE_CMD} -e 's|Tahoma-10\.fv1|${PREFIX}/lib/${PORTNAME}/&|' \
		${WRKSRC}/xrdp/xrdp_font.c
	@${REINPLACE_CMD} -Ee \
		's,(xrdp|ad)256\.bmp,${PREFIX}/lib/${PORTNAME}/&,' \
		${WRKSRC}/xrdp/xrdp_login_wnd.c
	@${REINPLACE_CMD} -e 's|cursor[01]\.cur|${PREFIX}/lib/${PORTNAME}/&|' \
		${WRKSRC}/xrdp/xrdp_wm.c
	@${REINPLACE_CMD} -e 's|/etc/pam\.d/sesman|${PREFIX}&|' \
		${WRKSRC}/sesman/verify_user_pam.c

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
