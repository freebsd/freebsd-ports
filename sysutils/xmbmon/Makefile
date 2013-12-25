# Created by: kaz@kobe1995.net (NAKAMURA Kauzushi)
# $FreeBSD$

PORTNAME=	xmbmon
PORTVERSION=	205
PORTREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/${PORTNAME}/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	MB monitor for LM78/79, W8378x, AS99127F, VT82C686 and ADM9240

LICENSE=	BSD

PORTSCOUT=	limit:^[0-9]+$
PATCH_SITES+=	${MASTER_SITES}
PATCHFILES+=	${PORTNAME}${PORTVERSION}_fflush.patch

ONLY_FOR_ARCHS=	i386 amd64
GNU_CONFIGURE=	yes

PORTDOCS=	ChangeLog ChangeLog.jp ReadMe ReadMe.jp ReadMe.tech

OPTIONS_DEFINE=	ASUS SMB DOCS
OPTIONS_MULTI=	INTERFACE
OPTIONS_MULTI_INTERFACE=	CLI X11
OPTIONS_DEFAULT=SMB CLI
ASUS_DESC=	"Enable A7N8X-VM support"
SMB_DESC=	"Enable smb(4) support"
CLI_DESC=	"CLI support only"

ASUS_PATCHFILES=	${PORTNAME}${PORTVERSION}_A7N8X-VM.patch
X11_PLIST_FILES=	lib/X11/app-defaults/${PORTNAME} \
			man/man1/${PORTNAME}.1x.gz
CLI_PLIST_FILES=	bin/mbmon \
			man/man1/mbmon.1.gz

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MX11}
MAKE_ARGS=	PROGRAM="mbmon"
.else
USE_XORG=	x11 xt
.endif

.if ${PORT_OPTIONS:MCLI}
USE_RC_SUBR=	mbmon
.endif

post-patch:
	@${REINPLACE_CMD} -e 's+/usr/share/doc/mbmon+${STAGEIR}${DOCSDIR}+' ${WRKSRC}/mbmon.1
	@${REINPLACE_CMD} -e 's+%%STAGEDIR%%%%PREFIX%%+${STAGEDIR}${PREFIX}+' ${WRKSRC}/Makefile.in
.if !${PORT_OPTIONS:MX11}
	@${REINPLACE_CMD} -e '/p xmbmon/d' ${WRKSRC}/Makefile.in
.endif
.if !${PORT_OPTIONS:MCLI}
	@${REINPLACE_CMD} -e '/p mbmon/d' ${WRKSRC}/Makefile.in
.endif
.if ${PORT_OPTIONS:MSMB}
	@${REINPLACE_CMD} -e 's/^DEFS=/&-DSMBUS_IOCTL /' ${WRKSRC}/Makefile.in
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
