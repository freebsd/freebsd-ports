# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	mew
PORTVERSION=	6.5
PORTREVISION=	4
CATEGORIES=	mail elisp
MASTER_SITES=	http://www.mew.org/Release/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Messaging in the Emacs World for emacs

OPTIONS_DEFINE=	DATABASE DOCS
DATABASE_DESC=	Database feature support (with Ruby & Sqlite3)

# emacs port setup
USE_EMACS=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDATABASE}
RUN_DEPENDS=	rubygem-sqlite3>=0:${PORTSDIR}/databases/rubygem-sqlite3
.endif


SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-elispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/mew \
		--with-etcdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/mew/etc

# target name for make build and install
ALL_TARGET=	all info
INSTALL_TARGET=	install
.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	jinfo
INSTALL_TARGET+=install-jinfo
.endif

# manuals
MAN1=		cmew.1 mew-pinentry.1 mewcat.1 mewdecode.1 mewencode.1 mewest.1 mewl.1 smew.1 incm.1
INFO=		mew
.if ${PORT_OPTIONS:MDOCS}
INFO+=		mew.ja
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} ; \
		${INSTALL_DATA} 00* dot.* ${DOCSDIR}/ ; \
		)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
