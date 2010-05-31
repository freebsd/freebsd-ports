# New ports collection makefile for:	Xaw3d
# Date created:		18 November 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	Xaw3d
PORTVERSION=	1.5E
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.visi.com/users/hawkeyd/X/ \
		http://www.mirrorservice.org/sites/ftp.slackware.com/pub/slackware/slackware_source/x/xaw3d/ \
		ftp.slackware.com/pub/slackware/slackware_source/x/xaw3d/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A 3-D Athena Widget set that looks like Motif

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USE_IMAKE=	yes
USE_XORG=	x11 xext xmu xt sm ice xpm
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message
SUB_LIST=	XAWVER="${XAWVER}"

OPTIONS=	NLS "Provide limited Natural Language Support via gettext" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	${MKDIR} ${WRKSRC}/X11/Xaw3d
	cd ${WRKSRC}/X11/Xaw3d; ${LN} -sf ../../*.h .
.if defined(WITHOUT_NLS)
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.XAW3D ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
