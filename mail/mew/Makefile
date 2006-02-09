# New ports collection makefile for: Mew
# Date created:		21 November 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#			Hiroto Kagotani <hiroto.kagotani@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mew
PORTVERSION=	4.2
CATEGORIES=	mail elisp
MASTER_SITES=	http://www.Mew.org/Release/ \
		${MASTER_SITE_PORTS_JP}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	hiroto.kagotani@gmail.com
COMMENT?=	Messaging in the Emacs World for emacs

# document install directory by install-doc target
DOCSDIR=	share/doc/${PORTNAME}

# emacs port setup
USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS+=	EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

# target name for make build and install
ALL_TARGET?=	all info jinfo
INSTALL_TARGET?=	install install-jinfo

# manuals
MAN1=		mewcat.1 mewdecode.1 mewencode.1 mewl.1 incm.1
INFO=		mew mew.jis

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

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
