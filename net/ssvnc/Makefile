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

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	stunnel:${PORTSDIR}/security/stunnel \
		xterm:${PORTSDIR}/x11/xterm

OPTIONS_DEFINE=	ULTRAFTP DOCS
ULTRAFTP_DESC=	UltraVNC File Transfer support (Java required)

USES=		imake:env gmake perl5
USE_XORG=	xi xmu xt xaw ice xpm xext sm
USE_TK_WRAPPER=	yes
USE_PERL5=	run

MAKE_ENV+=	ROOT=${STAGEDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MULTRAFTP}
USE_JAVA=	yes
PLIST_SUB+=	ULTRAFTP=""
.else
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
.if ! ${PORT_OPTIONS:MULTRAFTP}
	@${REINPLACE_CMD} -e "s|sh -c 'type javac'|:|" \
		-e "s|sh -c 'type jar'|:|" \
		-e 's|cd $$(JSRC);|: |' \
		-e 's|cp -p $$(ARCHIVE)|:|' \
		${WRKSRC}/Makefile
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} config

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
.for man in ssvnc.1 ssvncviewer.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/${man} \
		${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
.endif

.include <bsd.port.mk>
