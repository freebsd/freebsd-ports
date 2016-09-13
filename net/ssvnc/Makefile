# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssvnc
PORTVERSION=	1.0.29
PORTREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}.src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced TightVNC Viewer (SSVNC: SSL/SSH VNC viewer)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	stunnel:security/stunnel \
		xterm:x11/xterm

USES=		gmake imake:env jpeg perl5 ssl tk:wrapper
USE_PERL5=	run
USE_XORG=	xi xmu xt xaw ice xpm xext sm
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

OPTIONS_DEFINE=	DOCS ULTRAFTP
OPTIONS_SUB=	yes

ULTRAFTP_DESC=	UltraVNC File Transfer support (Java required)
ULTRAFTP_USE=	JAVA=yes

MAKE_ENV+=	ROOT=${STAGEDIR}

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MULTRAFTP}
MAKE_ARGS+=	JSRC=""
.endif

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_ARGS+=	DOCS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|grep Linux|grep ${OPSYS}|' \
		${WRKSRC}/scripts/util/ss_vncviewer
	@${REINPLACE_CMD} -e 's|[[:<:]]ssvnc[[:>:]]|ssvnc-gui|' \
		${WRKSRC}/man/man1/ssvnc.1

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} config)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ssvnc/*.so
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
.for man in ssvnc.1 ssvncviewer.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/${man} \
		${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
