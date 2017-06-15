# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	mew
PORTVERSION=	6.7
CATEGORIES=	mail elisp
MASTER_SITES=	http://www.mew.org/Release/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Messaging in the Emacs World for emacs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/00copyright

OPTIONS_DEFINE=	DATABASE DOCS STUNNEL
OPTIONS_DEFAULT=STUNNEL
DATABASE_DESC=	Support database feature (with Ruby & Sqlite3)
DATABASE_RUN_DEPENDS=	rubygem-sqlite3>=0:databases/rubygem-sqlite3
STUNNEL_DESC=	Support SSL feature using stunnel
STUNNEL_RUN_DEPENDS=	stunnel>=0:security/stunnel

# emacs port setup
USE_EMACS=	yes
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-elispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/mew \
		--with-etcdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/mew/etc

# target name for make build and install
ALL_TARGET=	all info
INSTALL_TARGET=	install
INFO=		mew
DOCS_ALL_TARGET=	jinfo
DOCS_INSTALL_TARGET=	install-jinfo
DOCS_INFO=	mew.ja
PORTDOCS=	00api 00changes.0 00changes.1 00changes.2 00changes.3 \
		00changes.4.1 00changes.4.2 00changes.5.1 00changes.5.2 \
		00changes.6.1 00changes.6.2 00changes.6.3 00changes.6.4 \
		00changes.6.5 00changes.6.6 00changes.6.7 \
		00diff 00readme dot.emacs dot.mew dot.theme

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/${INFO_PATH}/*.info.~1~

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
