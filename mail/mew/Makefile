# New ports collection makefile for: Mew
# Date created:		21 November 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#			Hiroto Kagotani <hiroto.kagotani@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mew
PORTVERSION=	6.2
CATEGORIES=	mail elisp
MASTER_SITES=	http://www.Mew.org/Release/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	hiroto.kagotani@gmail.com
COMMENT?=	Messaging in the Emacs World for emacs

OPTIONS=	DATABASE "Database feature support (with Ruby & Sqlite3)" on

# emacs port setup
USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs22

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DATABASE)
RUN_DEPENDS=	rubygem-sqlite3>=0:${PORTSDIR}/databases/rubygem-sqlite3
.endif

MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-elispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/mew \
		--with-etcdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/mew/etc

# target name for make build and install
ALL_TARGET=	all info
INSTALL_TARGET=	install
.if !defined(NOPORTDOCS)
ALL_TARGET+=	jinfo
INSTALL_TARGET+=install-jinfo
.endif

# manuals
MAN1=		cmew.1 mew-pinentry.1 mewcat.1 mewdecode.1 mewencode.1 mewest.1 mewl.1 smew.1 incm.1
INFO=		mew
.if !defined(NOPORTDOCS)
INFO+=		mew.jis
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} ; \
		${INSTALL_DATA} 00* mew.dot.* ${DOCSDIR}/ ; \
		for dir in contrib; do \
			${CP} -R $${dir} ${DOCSDIR}/ ; \
		done)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
