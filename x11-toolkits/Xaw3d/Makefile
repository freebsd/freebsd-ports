# Created by: asami
# $FreeBSD$

PORTNAME=	Xaw3d
PORTVERSION=	1.5E
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.visi.com/users/hawkeyd/X/ \
		ftp.slackware.com/pub/slackware/slackware_source/x/xaw3d/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3-D Athena Widget set that looks like Motif

LICENSE=	MIT

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USES=		imake
USE_GCC=	any
USE_XORG=	x11 xext xmu xt sm ice xpm
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message
XAWVER=		8
SUB_LIST=	XAWVER="${XAWVER}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	${MKDIR} ${WRKSRC}/X11/Xaw3d
	cd ${WRKSRC}/X11/Xaw3d; ${LN} -sf ../../*.h .
.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/LINTLIBS =/s/=.*/=/' \
		-e '/#ifdef XawI18nDefines/s//#if 0/' \
		${WRKSRC}/Imakefile
.endif

# Workaround a bug in egcs on FreeBSD/Alpha.
.if ${ARCH} == "alpha"
post-configure:
	@(cd ${WRKSRC}; ${MV} Makefile Makefile.orig; ${SED} -e \
	  's/CDEBUGFLAGS = -O/CDEBUGFLAGS =/g' Makefile.orig > Makefile)
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.XAW3D ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
