# New ports collection makefile for:   emacs-w3m
# Date Created:			24 Mar 2001
# Whom:				MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	emacs-w3m
PORTVERSION=	0.2.150
CATEGORIES=	www elisp
MASTER_SITES=	http://namazu.org/~tsuchiya/emacs-w3m/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	w3m_el-${PORTVERSION}

MAINTAINER=	nobutaka@nobutaka.com

EMACS_PORT_NAME?=	emacs20

CONFIGURE_ARGS?=	--with-emacs=${EMACS_CMD}
LISPDIR?=	${EMACS_LIBDIR}/site-lisp/w3m
ETCDIR?=	share/w3m
PKGINFODIR?=	"@comment "

USE_AUTOCONF=	yes
ALL_TARGET=	default

PLIST_SUB+=	EMACS_NAME=${EMACS_NAME} \
		XEMACS_ONLY=${XEMACS_ONLY} \
		EMACS_ONLY=${EMACS_ONLY} \
		LISPDIR=${LISPDIR} \
		ETCDIR=${ETCDIR} \
		PKGINFODIR=${PKGINFODIR}

DOCS=		README
DOCS_JA=	README.ja TIPS.ja

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
DOCSDIR_JA=	${PREFIX}/share/doc/ja/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${EMACS_NAME} == xemacs
XEMACS_ONLY?=		""
EMACS_ONLY?=		"@comment "
.else
XEMACS_ONLY?=		"@comment "
EMACS_ONLY?=		""
.endif

post-extract:
.if defined(EMACS_PACKAGESDIR)
	@${CP} ${FILESDIR}/_pkg.el ${WRKSRC}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR_JA}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR_JA}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
