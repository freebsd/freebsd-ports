# New ports collection makefile for:	tramp (for emacs21)
# Date Created:		12 Dec 2001
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tramp
PORTVERSION=	0.0.20011228
CATEGORIES=	net elisp
MASTER_SITES=	http://tramp.sourceforge.net/download/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}

MAINTAINER=	yoichi@FreeBSD.org

EMACS_PORT_NAME?=	emacs21

USE_GMAKE=	yes
MAKE_ARGS+=	DIRS=lisp

TRAMP_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
DIRSECTION=	"The Emacs editor and associated tools"
INFOENTRY=	"* TRAMP: (tramp).                Transparent Remote Access, Multiple Protocol."
INFOENTRY_JA=	"* TRAMP-J: (tramp_ja).           Transparent Remote Access, Multiple Protocol."
PLIST_SUB+=	TRAMP_LISPDIR=${TRAMP_LISPDIR} \
		DIRSECTION=${DIRSECTION} \
		INFOENTRY=${INFOENTRY} INFOENTRY_JA=${INFOENTRY_JA}

.if !defined(NOPORTDOCS) && defined(JAPANESE_INFO)
BUILD_DEPENDS+=	jmakeinfo:${PORTSDIR}/japanese/texinfo
PLIST_SUB+=	JAPANESE_INFO=""
.else
PLIST_SUB+=	JAPANESE_INFO="@comment "
.endif

.if ${EMACS_PORT_NAME} == emacs20
PLIST_SUB+=	EMACS20_ONLY=""
.else
PLIST_SUB+=	EMACS20_ONLY="@comment "
.endif

post-patch:
	${PERL} -pi -e "s@ format-spec.elc@@g;\
			s@ base64.elc@@g" ${WRKSRC}/lisp/Makefile

post-build:
.if ${EMACS_PORT_NAME} == emacs20
	(cd ${WRKSRC}/contrib; ${GMAKE} EMACS=${EMACS_CMD} format-spec.elc)
.endif
.if !defined(NOPORTDOCS) && defined(JAPANESE_INFO)
	(cd ${WRKSRC}/texi; jmakeinfo --no-split tramp_ja.texi)
.endif
	${RM} ${WRKSRC}/lisp/base64.el ${WRKSRC}/lisp/format-spec.el

do-install:
	${MKDIR} ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${WRKSRC}/lisp/*.elc ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
.if ${EMACS_PORT_NAME} == emacs20
	${INSTALL_DATA} ${WRKSRC}/contrib/format-spec.el ${WRKSRC}/contrib/format-spec.elc ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
.endif
	${INSTALL_DATA} ${WRKSRC}/tramp2/*.el ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/texi/tramp.info ${PREFIX}/info
	install-info --section=${DIRSECTION} --entry=${INFOENTRY} ${PREFIX}/info/tramp.info ${PREFIX}/info/dir
.if defined(JAPANESE_INFO)
	${INSTALL_DATA} ${WRKSRC}/texi/tramp_ja.info ${PREFIX}/info
	install-info --section=${DIRSECTION} --entry=${INFOENTRY_JA} ${PREFIX}/info/tramp_ja.info ${PREFIX}/info/dir
.endif
.endif

.include <bsd.port.mk>
