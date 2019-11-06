# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssvnc
PORTVERSION=	1.0.29
PORTREVISION=	4
CATEGORIES=	net security
MASTER_SITES=	SF
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced TightVNC Viewer (SSVNC: SSL/SSH VNC viewer)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	stunnel:security/stunnel \
		xterm:x11/xterm

USES=		gmake imake:env jpeg perl5 ssl tk:wrapper xorg
USE_PERL5=	run
USE_XORG=	ice sm x11 xaw xext xi xmu xpm xt

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAKE_ENV+=	ROOT=${STAGEDIR}

OPTIONS_DEFINE=	DOCS ULTRAFTP
OPTIONS_SUB=	yes

DOCS_MAKE_ARGS_OFF=	DOCS=""

ULTRAFTP_DESC=		UltraVNC File Transfer support (Java required)
ULTRAFTP_USE=		JAVA=yes
ULTRAFTP_MAKE_ARGS_OFF=	JSRC=""

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|netstat -ant|netstat -an|' \
		${WRKSRC}/scripts/util/ss_vncviewer
	@${REINPLACE_CMD} -e 's|[[:<:]]ssvnc[[:>:]]|ssvnc-gui|' \
		${WRKSRC}/man/man1/ssvnc.1

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} config)

.include <bsd.port.post.mk>
