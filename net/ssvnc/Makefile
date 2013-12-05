# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssvnc
PORTVERSION=	1.0.29
CATEGORIES=	net security
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}.src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced TightVNC Viewer (SSVNC: SSL/SSH VNC viewer)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjpeg.so.11:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	stunnel:${PORTSDIR}/security/stunnel \
		xterm:${PORTSDIR}/x11/xterm

OPTIONS_DEFINE=	DOCS ULTRAFTP
ULTRAFTP_DESC=	UltraVNC File Transfer support (Java required)

USES=		imake:env gmake perl5 tk:wrapper
USE_XORG=	xi xmu xt xaw ice xpm xext sm
USE_PERL5=	run

MAKE_ENV+=	ROOT=${STAGEDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MULTRAFTP}
USE_JAVA=	yes
PLIST_SUB+=	ULTRAFTP=""
.else
MAKE_ARGS+=	JSRC=""
PLIST_SUB+=	ULTRAFTP="@comment "
.endif

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_ARGS+=	DOCS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|grep Linux|grep ${OPSYS}|' ${WRKSRC}/scripts/util/ss_vncviewer
	@${REINPLACE_CMD} -e 's|[[:<:]]ssvnc[[:>:]]|ssvnc-gui|' ${WRKSRC}/man/man1/ssvnc.1
	@${REINPLACE_CMD} -e 's|/usr/local/bin|${LOCALBASE}/bin|' \
		-e 's|^CC =|CC ?=|' ${WRKSRC}/vncstorepw/Makefile

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} config

post-install:
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
.for man in ssvnc.1 ssvncviewer.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/${man} \
		${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
