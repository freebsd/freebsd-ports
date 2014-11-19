# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	mew
PORTVERSION=	6.6
PORTREVISION=	1
CATEGORIES=	mail elisp
MASTER_SITES=	http://www.mew.org/Release/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Messaging in the Emacs World for emacs

OPTIONS_DEFINE=	DATABASE DOCS STUNNEL
OPTIONS_DEFAULT=STUNNEL
DATABASE_DESC=	Support database feature (with Ruby & Sqlite3)
STUNNEL_DESC=	Support SSL feature using stunnel

DATABASE_RUN_DEPENDS=	rubygem-sqlite3>=0:${PORTSDIR}/databases/rubygem-sqlite3
STUNNEL_RUN_DEPENDS=	stunnel>=0:${PORTSDIR}/security/stunnel

# emacs port setup
USE_EMACS=	yes
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-elispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/mew \
		--with-etcdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/mew/etc

.include <bsd.port.options.mk>

# target name for make build and install
ALL_TARGET=	all info
INSTALL_TARGET=	install
.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	jinfo
INSTALL_TARGET+=install-jinfo
.endif

INFO=		mew
.if ${PORT_OPTIONS:MDOCS}
INFO+=		mew.ja
.endif

post-install:
	@${RM} -f ${STAGEDIR}${PREFIX}/${INFO_PATH}/*.info.~1~
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} ; \
		${INSTALL_DATA} 00* dot.* ${STAGEDIR}${DOCSDIR}/ ; \
		)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
