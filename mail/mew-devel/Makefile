PORTNAME=	mew
DISTVERSIONPREFIX=	v
DISTVERSION=	6.8-72
DISTVERSIONSUFFIX=	-gfc4bca6
PORTREVISION=	3
CATEGORIES=	mail elisp
PKGNAMESUFFIX=	-devel${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Messaging in the Emacs World for emacs (Development Version)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/00copyright

USES=		emacs
USE_GITHUB=	yes

GH_ACCOUNT=	kazu-yamamoto
GH_PROJECT=	Mew

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-elispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/mew \
		--with-etcdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/mew/etc

CONFLICTS_INSTALL=	mew mew-emacs_* mew-devel-emacs_* # bin/cmew bin/incm

# target name for make build and install
ALL_TARGET=	all info
INSTALL_TARGET=	install

SUB_FILES=	pkg-message

INFO=		mew

PORTDOCS=	00api 00changes.0 00changes.1 00changes.2 00changes.3 \
		00changes.4.1 00changes.4.2 00changes.5.1 00changes.5.2 \
		00changes.6.1 00changes.6.2 00changes.6.3 00changes.6.4 \
		00changes.6.5 00changes.6.6 00changes.6.7 00changes.6.8 00diff \
		00readme dot.emacs dot.mew dot.theme

OPTIONS_DEFINE=		DATABASE DOCS STUNNEL
OPTIONS_DEFAULT=	STUNNEL
DATABASE_DESC=		Support database feature (with Ruby & Sqlite3)
DATABASE_RUN_DEPENDS=	rubygem-sqlite3>=0:databases/rubygem-sqlite3
DOCS_ALL_TARGET=	jinfo
DOCS_INSTALL_TARGET=	install-jinfo
DOCS_INFO=		mew.ja
STUNNEL_DESC=		Support TLS
STUNNEL_RUN_DEPENDS=	stunnel>=0:security/stunnel

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
