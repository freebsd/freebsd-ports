# New ports collection makefile for:	ssvnc
# Date created:				2007-04-22
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	ssvnc
PORTVERSION=	1.0.22
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}.src${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Enhanced TightVNC Viewer (SSVNC: SSL/SSH VNC viewer)

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake
LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	stunnel:${PORTSDIR}/security/stunnel \
		xterm:${PORTSDIR}/x11/xterm

USE_GMAKE=	yes
USE_XORG=	xi xmu xt xaw ice xpm xext sm
USE_TCL_RUN=	84
USE_TK_RUN=	84
USE_PERL5_RUN=	yes

MAN1=		ssvnc-gui.1 ssvncviewer.1

OPTIONS=	ULTRAFTP "UltraVNC File Transfer support (Java required)"	off

.include <bsd.port.options.mk>

.if defined(WITH_ULTRAFTP)
USE_JAVA=	yes
PLIST_SUB+=	ULTRAFTP=""
.else
PLIST_SUB+=	ULTRAFTP="@comment "
.endif
.if defined(NOPORTDOCS)
MAKE_ARGS+=	DOCS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|exec wish|exec ${WISH}|' ${WRKSRC}/scripts/util/ssvnc.tcl
	@${REINPLACE_CMD} -e 's|grep Linux|grep ${OPSYS}|' ${WRKSRC}/scripts/util/ss_vncviewer
	@${REINPLACE_CMD} -e 's|[[:<:]]ssvnc[[:>:]]|ssvnc-gui|' ${WRKSRC}/man/man1/ssvnc.1
.if !defined(WITH_ULTRAFTP)
	@${REINPLACE_CMD} -e "s|sh -c 'type javac'||" \
		-e "s|sh -c 'type jar'||" \
		-e 's|cd $$(JSRC);|@#|' \
		-e 's|cp -p $$(ARCHIVE)|@#|' \
		${WRKSRC}/Makefile
.endif

do-configure:
	@cd ${WRKSRC} && ${GMAKE} config

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
