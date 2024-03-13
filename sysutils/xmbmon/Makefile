PORTNAME=	xmbmon
PORTVERSION=	205
PORTREVISION=	16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/${PORTNAME}/
DISTNAME=	${PORTNAME}${PORTVERSION}

PATCH_SITES+=	${MASTER_SITES}
PATCHFILES+=	${PORTNAME}${PORTVERSION}_fflush.patch

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MB monitor for LM78/79, W8378x, AS99127F, VT82C686 and ADM9240
WWW=		http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/download.html

LICENSE=	BSD2CLAUSE

DEPRECATED=	These hardwares are no longer available and the port is no longer relevant
EXPIRATION_DATE=	2024-04-13

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=	yes

PORTSCOUT=	skipv:205conf

PORTDOCS=	ChangeLog ChangeLog.jp ReadMe ReadMe.jp ReadMe.tech

OPTIONS_DEFINE=	ASUS SMB DOCS
OPTIONS_DEFAULT=SMB CLI
OPTIONS_MULTI=	INTERFACE
OPTIONS_MULTI_INTERFACE=	CLI X11

ASUS_DESC=	Enable A7N8X-VM support
CLI_DESC=	CLI support only
SMB_DESC=	Enable smb(4) support

ASUS_PATCHFILES=	${PORTNAME}${PORTVERSION}_A7N8X-VM.patch
CLI_PLIST_FILES=	"@mode 4555"\
			bin/mbmon \
			@mode\
			share/man/man1/mbmon.1.gz
CLI_VARS=		USE_RC_SUBR=mbmon
X11_USES=	xorg
X11_USE=	XORG=x11,xt
X11_MAKE_ARGS_OFF=	PROGRAM="mbmon"
X11_PLIST_FILES=	"@mode 4555"\
			bin/xmbmon \
			@mode\
			lib/X11/app-defaults/XMBmon \
			share/man/man1/${PORTNAME}.1x.gz

post-patch:
	@${REINPLACE_CMD} -e 's+/usr/share/doc/mbmon+${DOCSDIR}+' \
		${WRKSRC}/mbmon.1

post-patch-SMB-on:
	@${REINPLACE_CMD} -e 's/^DEFS=/&-DSMBUS_IOCTL /' ${WRKSRC}/Makefile.in

do-install:
	@${DO_NADA}

do-install-CLI-on:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mbmon.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-install-X11-on:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xmbmon.resources \
		${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XMBmon
	${INSTALL_MAN} ${WRKSRC}/xmbmon.1x ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
