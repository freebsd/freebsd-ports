# New ports collection makefile for: Mew
# Date created:		21 November 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mew
PORTVERSION=	${MEW_VER}
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/ \
		${MASTER_SITE_PORTS_JP}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Message interface to Emacs Window (version 3) for emacs21

LATEST_LINK=	mew3

# Mew major version
MEW_MAJOR_VER=	3

# distfile version
MEW_VER=	${MEW_MAJOR_VER}.3

# document install directory by install-doc target
DOCSDIR=	share/doc/${PORTNAME}${MEW_MAJOR_VER}

# emacs port setup
EMACS_PORT_NAME?=	emacs21

# target name for make build and install
ALL_TARGET?=	all info jinfo
INSTALL_TARGET?=	install install-info install-jinfo install-etc

# environments
USE_REINPLACE=	yes
REINPLACE_ARGS=
MAKE_ENV+=	EMACS_LIBDIR=${EMACS_LIBDIR} MEW_MAJOR_VER=${MEW_MAJOR_VER}
PLIST_SUB+=	MEW_MAJOR_VER=${MEW_MAJOR_VER}
INFO?=		mew${MEW_MAJOR_VER} mew${MEW_MAJOR_VER}.jis

# manuals
MAN1=		mewcat.1 mewdecode.1 mewencode.1 mewls.1 incm.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Does not build on ia64"
.endif

post-patch:
	for f in mew-key.el info/mew.texi; do \
		${REINPLACE_CMD} -i "" -E \
			-e 's,%%MEW_MAJOR_VER%%,${MEW_MAJOR_VER},g' \
			${WRKSRC}/$${f}; \
	done

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCSDIR}
	(cd ${WRKSRC} ; \
		${INSTALL_DATA} 00* ${PREFIX}/${DOCSDIR}/ ; \
		for dir in contrib; do \
			${CP} -R $${dir} ${PREFIX}/${DOCSDIR}/ ; \
		done)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${DOCSDIR}
.endif

.include <bsd.port.post.mk>
