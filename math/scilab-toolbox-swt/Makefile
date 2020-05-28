# $FreeBSD$

PORTNAME=	swt
PORTVERSION=	0.3.1
CATEGORIES=	math
MASTER_SITES=	http://atoms.scilab.org/toolboxes/swt/${PORTVERSION}/files/
PKGNAMEPREFIX=	scilab-toolbox-
DISTNAME=	${PORTNAME}-${PORTVERSION}-3-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scilab 1-D and 2-D Wavelet Toolbox

BUILD_DEPENDS=	${SCILAB_CMD}:math/scilab
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		dos2unix zip
USE_LOCALE=	en_US.UTF-8

SCILAB_CMD=	${LOCALBASE}/bin/scilab-adv-cli
SCILAB_ARGS=	-noatomsautoload -nb -nouserstartup
MAKE_ENV=	SCI_JAVA_ENABLE_HEADLESS=1 SCI_DISABLE_TK=1
DOS2UNIX_FILES=	etc/swt.start

CONTRIBDIR?=	share/scilab/contrib
TOOLBOXDIR_REL?=	${CONTRIBDIR}/${PORTNAME}
TOOLBOXDIR=	${PREFIX}/${TOOLBOXDIR_REL}
PLIST_SUB=	TOOLBOXDIR=${TOOLBOXDIR_REL}
TOOLBOX_SUBDIRS=	demos etc macros

OPTIONS_DEFINE=	HELP
OPTIONS_DEFAULT=	HELP
OPTIONS_SUB=	yes

HELP_DESC=	Build help files (requires scilab with gui support)

WRKSRC=		${WRKDIR}/swt

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MHELP}
SCILAB_ARGS+=	-nwni
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-etc__swt.start
.else
TOOLBOX_SUBDIRS+=	jar
.endif

post-patch:
.if !${PORT_OPTIONS:MHELP}
	${REINPLACE_CMD} -e '/tbx_builder_help/d' ${WRKSRC}/builder.sce
.endif
	${ECHO_CMD} quit >> ${WRKSRC}/builder.sce

pre-build:
	${FIND} -d ${WRKSRC} \( -name '*.orig' -or -name '*.bak' \) -delete

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${SCILAB_CMD} ${SCILAB_ARGS} -f builder.sce

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${TOOLBOXDIR} "-name *\.so -or -name loader*\.sce"
.for d in ${TOOLBOX_SUBDIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${TOOLBOXDIR}
.endfor
	${FIND} ${STAGEDIR}${TOOLBOXDIR} -name *\.so -exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
