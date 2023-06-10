PORTNAME=	incron
DISTVERSION=	2017-11-13
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	joh.hendriks@gmail.com
COMMENT=	Handle filesystem-events the way cron handles time ones
WWW=		https://inotify.aiken.cz/?section=incron&page=about

LICENSE=	GPLv2 LGPL21 MIT
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE-GPL
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE-LGPL
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-X11

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		compiler localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	ar-
GH_TAGNAME=	81421d3a8bde0989d7e167d8a814d5232896c930
USE_RC_SUBR=	${PORTNAME}

MAKE_ARGS=	PREFIX="${PREFIX}" USER=${UID}	\
		DOCDIR="${PREFIX}/etc"	\
		MANPATH=${MANPREFIX}/man

CPPFLAGS+=	-D__NR_inotify_init
LDFLAGS+=	-linotify

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
EXTRA_PATCHES=	${FILESDIR}/extra-patch-FreeBSD_14
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/etc/incron,${PREFIX}/etc/incron,'	\
		${WRKSRC}/*conf* ${WRKSRC}/Makefile ${WRKSRC}/*.[158h]	\
		${WRKSRC}/*.cpp
	${REINPLACE_CMD} -e '/INITDIR/d' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
